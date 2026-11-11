#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, c, m, p, wy, a[N], h[N * 3], cnt, d[N * 3], v[N * 3];
struct node{
	int to, next, w;
}e[N * 5];
void add(int x, int y, int z){
	e[++cnt].to = y;
	e[cnt].next = h[x];
	e[cnt].w = z;
	h[x] = cnt;
}
void dij(int x){
	memset(d, 0x3f, sizeof d);
	memset(v, 0, sizeof v);
	priority_queue<pair<long long, int>> q;
	q.push({0, x});
	d[x] = 0;
	while(!q.empty()){
		int a = q.top().second;
		q.pop();
		for(int i = h[a]; i; i = e[i].next){
			int j = e[i].to, w = e[i].w;
			if(d[j] > d[a] + w) d[j] = d[a] + w, q.push({-d[j], j});
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> m >> n >> wy >> p;
	for(int i = 1, x; i <= n; i++) cin >> x, add(i, i + n, x), add(i + n, i, x);
	for(int i = 1, k; i <= m; i++){
		cin >> k;
		for(int j = 1, x, y; j <= k; j++){
			cin >> x >> y;
			add(x + n, 2 * n + i, y);
			add(2 * n + i, x + n, y);
		}
	}
	for(int i = 1, x, y; i <= p; i++){
		cin >> x >> y;
		dij(x);
		cout << d[y] << '\n';
	}
	return 0;
}

