#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
constexpr int BASE = 10000000;
struct Edge{
    int w;
    pair<int, int> v;
};

int ent[500005];
map<int, vector<Edge>> m[500000];
int tmp[500005];
int res[500005][20];
bool vis[500005][20];

int dfs(int u){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push(pair<int, pair<int, int>>(0, pair<int, int>(u, 0)));
    res[u][0] = 0;
    while(!q.empty()){
        auto h = q.top();
        q.pop();
        vis[q] = 1;
        for(const auto& v : m[h.second.first][h.second.second]){
            if(vis[v.v.first][v.v.second]) continue;
            res[v.v.first][v.v.second] = min(res[v.v.first][v.v.second], res[h.second.first][h.second.second] + v.w);
            q.push(pair<int, pair<int, int>>(res[v.v.first][v.v.second], v));
        }
    }
    return 0;
}

signed main()
{
    int c, n, m, d, q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i ++) cin>>ent[i];
    for(int i = 1; i <= n; i ++){
        int k;
        cin>>k;
        for(int j = 1; j <= k; j ++)
        {
            cin>>tmp[j]>>tmp[j+1];
            ::m[tmp[j]][0].push_back(Edge{tmp[j+1], pair<int, int>(tmp[j], i)});
            ::m[tmp[j]][i].push_back(Edge{tmp[j+1], pair<int, int>(tmp[j], 0)});
            if(j != 1) 
                ::m[tmp[j]][i].push_back(Edge{0, pair<int, int>(tmp[j-1], i)}),
                ::m[tmp[j-1]][i].push_back(Edge{0, pair<int, int>(tmp[j], i)});
        }
    }
    for(int i = 1; i <= q; i ++){
        int j, k;
        cin>>j>>k;
        dfs(j);
        cout<<res[k][0] + ent[j] + ent[k]<<endl;
    }

}