#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll n,m,a[N],ans,sum1[N],sum2[N],f=1;
void dfs(int x,int l,ll sum){
    if(x==m+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=l+1;i<=n;i++){
        dfs(x+1,i,(x==1?a[i]:(sum&a[i])));
    }
}
ll pow2(ll a,ll b){
    ll sum=1;
    for(int i=1;i<=b;i++){
        sum*=a;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bool f1=0;
        for(int j=1;j<=20;j++){
            if(pow2(2,j)-1==a[i]){
                f1=1;
                break;
            }
        }
        if(!f1) f=0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);
        }
    }else if(m==n-1){
        sum1[1]=a[1];
        sum2[n]=a[n];
        for(int i=2;i<=n;i++){
            sum1[i]=(sum1[i-1]&a[i]);
        }
        for(int i=n-1;i>=1;i--){
            sum2[i]=(sum2[i+1]&a[i]);
        }
        for(int i=2;i<n;i++){
            ans=max(ans,(sum1[i-1]&sum2[i+1]));
            //cout<<sum1[i]<<" "<<sum2[i]<<'\n';
        }
        ans=max({ans,sum2[2],sum1[n-1]});
    }else if(f){
        sort(a+1,a+n+1);
        ans=a[n-m+1];
    }else{
        dfs(1,0,0);
    }
    cout<<ans;
    return 0;
}


