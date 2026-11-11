#include<bits/stdc++.h>
#define int long long
#define add(a,b,c) e[++idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx
using namespace std;

int c,n,m,d,q,ww[1<<20],k[1<<20],x[1<<20],y[1<<20];
int e[1<<22],w[1<<22],ne[1<<22],h[1<<22],idx;
int g[5005][5005];
vector<int> a[505],t[505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> ww[i];
    for(int i=1;i<=n;i++){
        cin >> k[i];
        a[i].resize(k[i]+1), t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++) cin >> a[i][j] >> t[i][j];
    }
    for(int i=1;i<=q;i++) cin >> x[i] >> y[i];
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++) g[i][i]=0;
    for(int id=1;id<=n;id++)
    for(int i=1;i<k[id];i++)
        for(int j=i+1;j<=k[id];j++){
            int u=a[id][i],v=a[id][j];
            g[u][v]=g[v][u]=min(g[u][v],t[id][i]+t[id][j]);
        }
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++){
        if(i==j) continue;
        for(int k=1;k<=m;k++){
            if(g[i][k]>1e18||g[k][j]>1e18) continue;
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
    }
    for(int i=1;i<=q;i++)
        cout << g[x[i]][y[i]]+ww[x[i]]+ww[y[i]] << endl;
    return 0;
}
