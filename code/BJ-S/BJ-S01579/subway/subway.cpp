#include<bits/stdc++.h>
using namespace std;
long long w[500010];
long long b[500010], t[500010];
struct node{
    long long v, w;
};
vector<node> a[500010];
priority_queue<int> q;
long long dis[500010], inq[500010];
void spfa(int x){
	dis[x] = 0;
    q.push(x);
    inq[x] = 1;
    while (!q.empty()){
        int u = q.top();
        q.pop();
        inq[u] = 0;
        for (auto x : a[u]){
			int v = x.v, w = x.w;
            if (dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                if (!inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n, m, x, d, q, u, v;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> x;
        for (int j = 1; j <= x; j++){
            cin >> b[j] >> t[j];
            for (int k = 1; k < j; k++){
                a[b[j]].push_back({b[k], t[j]+t[k]});
                a[b[k]].push_back({b[j], t[j]+t[k]});
            }
        }
    }
    while (q--){
        cin >> u >> v;
        for (int i = 1; i <= m; i++) dis[i] = 1e18;
        spfa(u);
        cout << dis[v]+w[u]+w[v] << "\n";
    }
    return 0;
}
