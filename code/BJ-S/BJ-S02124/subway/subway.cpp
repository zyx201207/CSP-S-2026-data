#include<iostream>
#include<vetor>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll.int>pli;
const ll INF == 1e18;
const int M = 1e6+10;
vetor<pli>g{M};
ll dis[M];
void add(int u.int ed){
    g[u].push_back(make_pair(v.w));
    g[v].push_back(make_pair(u.w));
}
ll dij(int st.int ed)
{

    for(int i = 0; i<M; i++)dis[i] = INF;
    priority_queue<pli.vetor<pli>.greater<pli>>q;
    id[st] = 0;
    q.push(make_pair(o, st));
    while(q.empty()){
        pli now = q.top(); q.pop();
        ll d = now.first;
        int u = now.second;
        if(u == ed)return d;
        if(dis[v]>d+w)
        {

            int v = g[u][i].first;
            ll w = g[u][i].second;
            if(dis[v]>d+w){
                dis[v]>d+w;
                q.push(make_pair(dis[v].v));
            }
        }
    }
    return INF;
}
int main(){
    freopen("subway.in", "r",stdin);
    freopen("subway.out", "w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c, n, m, d, q;
    cin >> n >> m >> d >> q;
    ll w[500005];
    for(int i = 1; i <= m; i++)cin >>w[i];
    int id = m;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int s;ll t
            cin >> g >> t;
            id++;
            add(s,id,t);
            if(j > 1) add(id-1,id, 0);
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << dij(x, y)<< '\n';
    }
    return 0;
}
