#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+5, M=5e5+5;
int c, n, m, d, q;
struct aaa{
    int l, t;
}sta[M][25];
int dis[N][N], w[M], scnt[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int a, t;
            scanf("%lld %lld",&a,&t);
            sta[a][++scnt[a]]={i,t};
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=scnt[i];j++){
            for(int k=1;k<j;k++){
                dis[sta[i][k].l][sta[i][j].l]=dis[sta[i][j].l][sta[i][k].l]=min(dis[sta[i][j].l][sta[i][k].l],sta[i][j].t+sta[i][k].t);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        int ans=1e18;
        for(int i=1;i<=scnt[u];i++){
            for(int j=1;j<=scnt[v];j++){
                ans=min(ans,dis[sta[u][i].l][sta[v][j].l]+sta[u][i].t+sta[v][j].t+w[u]+w[v]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
