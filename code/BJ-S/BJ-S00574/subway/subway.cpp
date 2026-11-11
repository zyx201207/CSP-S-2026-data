#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 5e5+10, D = 30;
int c,n,m,d,q,w[M],g[N][N];
struct node { int p,t; };
vector<node> cu[M];
inline int read() {
    char c=getchar();
    int ans=0,p=1;
    while(c<'0' || c>'9') {
        if(c=='-') p=-1;
        c=getchar();
    }
    while('0'<=c && c<='9') {
        ans=ans*10+(c-'0');
        c=getchar();
    }
    return ans*p;
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(); n=read(); m=read(); d=read(); q=read();
    for(int i=1;i<=m;i++)
        w[i]=read();
    for(int i=1;i<=n;i++) {
        int k; k=read();
        for(int j=1;j<=k;j++) {
            int a,t;
            a=read(); t=read();
            cu[a].push_back({i,t});
        }
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++)
        g[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<cu[i].size();j++)
            for(int k=0;k<cu[i].size();k++) {
                if(j==k) continue;
                g[cu[i][j].p][cu[i][k].p]=min(g[j][k],cu[i][j].t+cu[i][k].t);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    while(q--) {
        int x,y,ans=0x3f3f3f3f3f3f3f3f;
        x=read(); y=read();
        for(int i=0;i<cu[x].size();i++)
            for(int j=0;j<cu[y].size();j++)
                ans=min(ans,g[cu[x][i].p][cu[y][j].p]+cu[x][i].t+cu[y][j].t);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}