#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5, S = 505;
int c, n, m, d, q, x[N], y[N], W[N], k[S], t[S][N];
vector<pair<int, int> > g[N];
vector<int> str, st;
map<int, int> mp;
struct node{
    int u, frmu;
    long long d;
    bool operator < (const node &others) const{
        return d > others.d;
    }
};
void solve(){
    int ln = st.size();
    for(int i = 0; i < ln; i++){
        mp[st[i]] = i;
    }
    long long dis[ln][n + 2][2 * m];
    bool vis[ln][n + 2][2 * m];
    memset(dis, 0x3f, sizeof dis);
    for(int i = 0; i < ln; i++){
        priority_queue<node> q;
        q.push({st[i] + m, n + 1, 0});
        dis[i][n + 1][st[i] + m] = 0;
        while(!q.empty()){
            int u = q.top().u, frmu = q.top().frmu;
            q.pop();
            if(vis[i][u][frmu] == 1) continue;
            vis[i][u][frmu] = 1;
            if(u == st[i]){
                for(auto e : g[u]){
                    int v = e.first, w = e.second;
                    if(dis[i][w][v] > dis[i][frmu][u] + t[w][u]){
                        dis[i][w][v] = dis[i][frmu][u] + t[w][u];
                        q.push({v, w, dis[i][w][v]});
                    }
                }
            }else{
                for(auto e : g[u]){
                    int v = e.first, w = e.second;
                    if(v > m){
                        if(dis[i][w][v] > dis[i][frmu][u] + t[frmu][u]){
                            dis[i][w][v] = dis[i][frmu][u] + t[frmu][u];
                            q.push({v, w, dis[i][w][v]});
                        }
                    }else{
                        if(dis[i][w][v] > dis[i][frmu][u] + (t[w][u] + t[frmu][u]) * (w != frmu)){
                            dis[i][w][v] = dis[i][frmu][u] + (t[w][u] + t[frmu][u]) * (w != frmu);
                            q.push({v, w, dis[i][w][v]});
                        }
                    }

                }
            }

        }
    }
    for(int i = 1; i <= q; i++){
        long long ans = 1e18;
        for(int j = 0; j <= n + 1; j++){
            ans = min(ans, dis[mp[x[i]]][j][y[i] + m]);
        }
        cout << ans + W[x[i]] + W[y[i]] << "\n";
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> W[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        vector<int> vt;
        for(int j = 1, vtx, vty; j <= k[i]; j++){
            cin >> vtx >> vty;
            t[i][vtx] = vty;
            vt.push_back(vtx);
        }
        int len = vt.size();
        for(int j = 0; j < len - 1; j++){
            g[vt[j]].push_back(make_pair(vt[j + 1], i));
            g[vt[j + 1]].push_back(make_pair(vt[j], i));
        }
    }
    for(int i = 1; i <= m; i++){
        g[i + m].push_back(make_pair(i, 0));
        g[i].push_back(make_pair(i + m, 0));
    }
    for(int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
        str.push_back(x[i]);
    }
    sort(str.begin(), str.end());
    st.push_back(str[0]);
    int len = str.size();
    for(int i = 1; i < len; i++){
        if(str[i] != str[i - 1]){
            st.push_back(str[i]);
        }
    }
    solve();
    return 0;
}
