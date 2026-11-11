#include<bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N=(1<<21)+7;

int m;
int n,a[N],pre[N],ans;

// #define LOCAL_TEST CSP2026_RP++

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z;
    #ifndef LOCAL_TEST
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
    #endif
    cin>>n>>m;
    for(i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
    int t=a[1]; x=1;
    for(i=2;i<=n;++i) if(a[i]==t) x=i;
    ans=x;
    y=0;
    for(i=x+1;i<=n;++i) {
        if(t!=a[i]){
            t=a[i];
            x=pre[i-1]-pre[y];
            if(m>=(1ll*(i-1-y)*a[i]-x)){ // cerr<<(1ll*(i-1)*a[i]-x)<<endl;
                for(j=i;j<=n&&a[j]==t;++j);
                // cerr<<j<<" aaa"<<i<<endl;
                ans=max(ans,j-1-y);
            }else{
                for(;m<(1ll*(i-1-y)*a[i]-(pre[i-1]-pre[y]));++y);
                for(j=i;j<=n&&a[j]==t;++j);
                ans=max(ans,j-1-y);
            }
        }
    }cout<<ans<<endl;
    return 0; 
}