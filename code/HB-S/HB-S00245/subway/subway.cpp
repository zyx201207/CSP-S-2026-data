#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500050], k[505], dist[500050];
bool vis[500050];
vector<pair<int, int> > vec[500050];
struct node{
    int x, y, op, ans;
}tmp[100010];
struct com{
    int x, y;
    bool operator > (const com& o) const {
        return this -> y > o.y;
    }
};
bool cmp1(node a, node b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
bool cmp2(node a, node b){
    return a.op < b.op;
}
void dfs(int u){
    priority_queue<com, vector<com>, greater<com> > q;
    q.push({u, 0});
    dist[u] = 0;
    while(!q.empty()){
        com now = q.top(); q.pop();
        vis[now.x] = true;
        for(const pair<int, int>& it : vec[now.x]){
            if(vis[it.first]) continue;
            if(dist[now.x] + it.second < dist[it.first]){
                dist[it.first] = dist[now.x] + it.second;
            }
            q.push({it.first, dist[it.first]});
        }
    }
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        int u, v, l, r;
        cin >> u >> v;
        for(int j = 2; j <= k[i]; j++){
            cin >> l >> r;
            vec[u].push_back({l, v + r});
            vec[l].push_back({u, v + r});
            u = l, v = r;
        }
    }
    for(int i = 1; i <= q; i++){
        cin >> tmp[i].x >> tmp[i].y;
        tmp[i].op = i;
        if(tmp[i].x > tmp[i].y) swap(tmp[i].x, tmp[i].y);
    }
    sort(tmp + 1, tmp + 1 + q, cmp1);
    for(int i = 1; i <= n; i++){
        if(tmp[i].x != tmp[i - 1].x){
            memset(vis, false, sizeof vis);
			memset(dist, 127, sizeof dist);
            dfs(tmp[i].x);
            tmp[i].ans = dist[tmp[i].y] + w[tmp[i].x] + w[tmp[i].y];
        }else{
            tmp[i].ans = dist[tmp[i].y] + w[tmp[i].x] + w[tmp[i].y];
        }
    }
    sort(tmp + 1, tmp + 1 + q, cmp2);
    for(int i = 1; i <= q; i++){
        cout << tmp[i].ans << "\n";
    }
}
