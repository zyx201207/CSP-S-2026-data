#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace rp{
    const int N=2e6+7;
    int a[N],t[N],f[N];
    void slow() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    void calcb() {
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<n;i++) {
            int l=i,g=1,s=1;t[i]=0,f[i]=1;
            for(int j=i+1;j<=n;j++) {
                f[j]=t[j]=1e18+7;
                if(a[j]-a[j-1]>d) break;
                while(a[j]-a[l]>d) l++,g--,s-=f[l-1];
                if(g<=0){
                    g=0,s=0;
                    while(t[l]==t[l+g]) g++,s+=f[l+g-1];
                }
                //cout<<j<<' '<<l<<' '<<g<<' '<<s<<'\n';
                t[j]=t[l]+1;
                f[j]=s;
                if(t[j]==t[l]) g++,s+=f[i];
                if(f[j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    void main() {
        slow();
        int c;cin>>c;
        int t;cin>>t;while(t--) {
            calcb();
        }
    }
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    rp::main();
}
