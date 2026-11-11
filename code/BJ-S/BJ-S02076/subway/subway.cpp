#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+5, K = 2e4+5;
typedef long long ll;

int Data, n, m, kkk, T;
ll w[M];

vector <int> g[M];
vector <ll> h[M];

ll d[M];
bool vis[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> Data >> n >> m >> kkk >> T;
    for(int i=1; i<=m; i++)
        cin >> w[i];

    if((7 <= Data && Data <= 11) || !Data){
        for(int i=1; i<=n; i++){
            int qwert; cin >> qwert;
            int u, v; ll tu, tv;
            cin >> u >> tu >> v >> tv;
            g[u].push_back(v),
            g[v].push_back(u);
            h[u].push_back(tu+tv),
            h[v].push_back(tu+tv);
        }

        while(T--){
            int x, y; cin >> x >> y;
            queue <int> q; q.push(x);
            memset(vis, 0, sizeof(vis)); vis[x] = 1;
            for(int i=1; i<=m; i++) d[i] = LONG_LONG_MAX;
            d[x] = 0;

            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int i=0; i<g[u].size(); i++){
                    int v = g[u][i]; ll f = h[u][i];
                    if(vis[v]) continue;

                    vis[v] = 1;
                    q.push(v);
                    d[v] = min(d[u] + f, d[v]);

                }
            }

            cout << d[y]+w[x]+w[y] << '\n';
        }
    }


    return 0;
}
