#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int NN=5e3+10;
typedef long long ll;
ll a[N];
//struct node{
//    int u,v;
//}b[N*15];
ll dp[N],cnt[N];
ll n,d;
ll sol(int x){
    ll sum=0;
    for(int i=x;i<=n;i++)dp[i]=1e9,cnt[i]=0;
    dp[x]=0;
    cnt[x]=1;
    for(int i=x;i<=n;i++){
        int k=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        for(int j=i+1;j<=k;j++){
            if(dp[i]+1==dp[j]){
                cnt[j]+=cnt[i];
            }
            if(dp[i]+1<dp[j]){
                cnt[j]=cnt[i];
                dp[j]=dp[i]+1;
            }
        }
    }
    for(int i=x;i<=n;i++){
        if(cnt[i]==2)sum++;
    }
    return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==11||c==12){
            ll cnt=d/(a[2]-a[1]);
            if(cnt==0||cnt==1)cout<<0<<"\n";
            else cout<<max(0ll,n-cnt*2+1)<<"\n";
            continue;
        }
        ll sum=0;
        for(int i=1;i<n;i++)sum+=sol(i);
        cout<<sum<<"\n";
    }
    return 0;
}
