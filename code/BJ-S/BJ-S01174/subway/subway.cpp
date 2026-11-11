#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXM 500005
#define MAXN 505
int c,n,m,d,q;
long long w[MAXM];
vector<int> edge[MAXM << 1],len[MAXM << 1];
long long dis[MAXN][MAXN];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1; i <= m; i++) scanf("%lld",&w[i]);
    for(int i = 1; i <= n; i++){//m+i
        int tmp; scanf("%lld",&tmp);
        for(int j = 1; j <= tmp; j++){
            int k,t; scanf("%lld%lld",&k,&t);
            edge[k].push_back(m+i);
            edge[m+i].push_back(k);
            len[k].push_back(t);
            len[m+i].push_back(t);
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = 1e18;
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    //make the graph
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < edge[i].size(); j++){
            for(int k = j+1; k < edge[i].size(); k++){
                int u = edge[i][j] - m,v = edge[i][k] - m;
                dis[u][v] = min(dis[u][v],len[i][j] + len[i][k]);
                dis[v][u] = min(dis[v][u],len[i][j] + len[i][k]);
            }
        }
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    //cerr << dis[1][2] << " " << dis[2][1] << endl;
    for(int i = 1; i <= q; i++){
        int x,y; scanf("%lld%lld",&x,&y);
        long long ans = 1e18;
        for(int j = 0; j < edge[x].size(); j++){
            for(int k = 0; k < edge[y].size(); k++){
                int u = edge[x][j] - m,v = edge[y][k] - m;
                ans = min(ans,dis[u][v] + len[x][j] + len[y][k]);
            }
        }
        printf("%lld\n",ans + w[x] + w[y]);
    }
    return 0;
}