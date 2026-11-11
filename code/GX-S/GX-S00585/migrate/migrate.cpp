#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll c,t;
ll n,d;
ll a[305];
ll dp[305][305];
ll dfs(int l,int r,int bu,int pos){
    if(bu==n){
        if(pos==r)return 1;
        else return 0;
    }
    if(dp[pos][r]!=-1)return dp[pos][r];
    ll cou1=0,ans1=0;
    for(int i=l+1;i<=r;i++){
        cou1+=a[i]-a[i-1];
        if(d>=cou1){
            ans1+=dfs(l,r,bu+1,i);
        }
    }
    return dp[pos][r]=ans1;
}
ll fun(ll n){
    ll cnt=0;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            memset(dp,-1,sizeof dp);
            if(dfs(i,j,n,i)==2)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        ll l=0,r=n-1;
        ll maxm=0,maxi=-1,m=0;
        for(int i=l;i<=r;i++){
            m=fun(i);//re duishu
            maxm=max(maxm,m);
        }
        cout<<maxm<<endl;
    }
    return 0;
}
