#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
using ll = long long;
ll c,n,m,d,ask,w[maxn],t[505][maxn],a[505][maxn],k[maxn],xr,yr;
struct edge{
    int to;
    ll len;
};
vector<edge>v[1000005];
ll dist[maxn];
bool flag[maxn];
void Dijkstra(int s){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> >q;
    memset(dist,127,sizeof(dist));
    memset(flag,0,sizeof(flag));
    dist[s] = 0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u = q.top().first;
        int id = q.top().second;
        q.pop();
        if(flag[id])continue;
        flag[id] = true;
        for(auto t : v[id]){
            if(u + t.len < dist[t.to]){
                dist[t.to] = u + t.len;
                q.push(make_pair(dist[t.to],t.to));
            }
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> ask;
    for(int i = 1;i <= m;i++)cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)cin >> a[i][j] >> t[i][j];
    }
    for(int i = 1;i <= n;i++){
        int x = m + i;
        for(int j = 1;j <= k[i];j++){
            v[x].push_back(edge{a[i][j],t[i][j]});
            v[a[i][j]].push_back(edge{x,t[i][j]});
        }
    }
    for(int i = 1;i <= m;i++){
        int x = m + n + i;
        v[x].push_back(edge{i,w[i]});
        v[i].push_back(edge{x,w[i]});
    }
    while(ask--){
        cin >> xr >> yr;
        Dijkstra(xr + n + m);
        cout << dist[yr + n + m] << endl;
    }
    return 0;
}
