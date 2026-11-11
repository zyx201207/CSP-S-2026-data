#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5;
int n,h[N]; ll d;
ll a[N];
int f[N][3];

namespace n2 { 
    int f[N],c[N],cc[N];

    void bf() { 
        int ans=0;
        for(int i=1;i<=n;++i) {
            f[i-1]=c[i-1]=cc[i-1]=0;
            f[i]=0,c[i]=cc[i]=1;
            for(int j=i+1,lt=i,rt=i;j<=n;++j) {
                if(a[j]-a[j-1]>d) break;
                c[j]=cc[j]=0;
                for(;a[j]-a[lt]>d;++lt) ;
                rt=max(rt,lt); 
                for(;rt<j-1 && f[rt+1]==f[rt];++rt) ;
                f[j]=f[rt]+1; c[j]=cc[rt]-cc[lt-1];
                if(c[j]==2) ++ans;
                cc[j]=cc[j-1]+c[j];
            }
        }
        printf("%d\n",ans);
    }
};

void wk() {
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    for(int i=n,p=n;i>=1;--i) {
        for(;a[p]-a[i]>d;--p) ;
        h[i]=p;
    }
    if(n<=5000) { n2::bf(); return ; }
    for(int i=1;i<=n;++i) memset(f[i],0,sizeof f[i]);
    for(int i=n-1;i>=1;--i) {
        f[i][0]=h[i]-i;
        if(h[i]==i+1) f[i][0]+=f[h[i]][0];
        else if(h[h[i]-1]!=h[h[i]]) f[i][0]+=f[h[i]][0]-(h[h[i]-1]-h[i]);
        if(h[h[i]-1]==h[h[i]] && h[h[i]-2]==h[h[i]]) continue;
        // int lp=max(h[i]+1,h[h[i]-2]+1),rp=h[h[i]-1];
        // if(h[h[i]-1]==h[h[i]]-1) {
        //     f[i][1]=(h[h[i]-2]!=h[h[i]-1])*f[h[i]][1]+max(0,rp-lp+1);
        // }
        // else if(h[h[i]-1]==h[h[i]]) {
        //     f[i][1]=f[h[h[i]]][0]+max(0,rp-lp+1);
        // }
        // else {
        //     f[i][2]=f[h[i]][1]+f[h[i]][2];
        //     f[i][1]=max(0,rp-lp+1);
        // }
        // cerr << i << ' ' << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << "\n";

    }
    ll ans=0;
    for(int i=1;i<=n;++i) ans+=f[i][1]+f[i][2];
    printf("%lld\n",ans);
}

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t; scanf("%d%d",&c,&t);

    for(;t--;) wk();

    return 0;
}