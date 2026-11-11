#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505,M=5e5+5;
int c,n,m,d,q;
ll w[M],f[N][N];
struct node { int x; ll t; };
vector<node> v[M];

void wk() {
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
    for(int i=1,k;i<=n;++i) {
        scanf("%d",&k);
        for(int j=1,x,t;j<=k;++j) {
            scanf("%d%d",&x,&t);
            v[x].push_back((node){i,t});
        }
    }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i) f[i][i]=0;
    for(int i=1;i<=m;++i) {
        int o=v[i].size();
        for(int j=0;j<o;++j) for(int k=j+1;k<o;++k) {
            f[v[i][j].x][v[i][k].x]=min(f[v[i][j].x][v[i][k].x],v[i][j].t+v[i][k].t);
        }
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]=min(f[i][j],f[j][i]);
    for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int x,y;q--;) {
        ll ans=1ll<<60;
        scanf("%d%d",&x,&y);
        int o1=v[x].size(),o2=v[y].size();
        for(int j=0;j<o1;++j) for(int k=0;k<o2;++k) ans=min(ans,v[x][j].t+v[y][k].t+f[v[x][j].x][v[y][k].x]);
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
}

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    wk();

    return 0;
}