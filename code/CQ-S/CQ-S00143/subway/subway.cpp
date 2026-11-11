#include <bits/stdc++.h>
typedef long long ll;
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
const int N = 1e5 + 10, M = 510;
int c, n, m, p, k;
int w[N];
ll d[N][M];
vector<pii> a[N], b[N];
vector<int> r[N];
struct node{
	int f, s;
	ll d;
	bool operator <(const node &t)const{
		return d < t.d;
	}
};
priority_queue<node> q;
int find(int x, int y){
	return lower_bound(r[x].begin(), r[x].end(), y) - r[x].begin();
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> p >> k;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		while (k--){
			int x, y;
			cin >> x >> y;
			a[x].push_back({i, y});
			r[x].push_back(i);
			b[i].push_back({x, y});
		}
	}
	while (k--){
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < a[i].size(); j++)
				d[i][a[i][j].f] = 0x3f3f3f3f;
		for (int i = 0; i < a[x].size(); i++) q.push({x, i, w[x] + a[x][i].s}), d[x][a[x][i].f] = w[x] + a[x][i].s;
		while (!q.empty()){
			node t = q.top(); q.pop();
			int xl = a[t.f][t.s].f;
			for (int i = 0; i < a[t.f].size(); i++)
				if (i != t.s && d[t.f][a[t.f][i].f] > t.d + a[t.f][t.s].s + a[t.f][i].s)
					d[t.f][a[t.f][i].f] = t.d + a[t.f][t.s].s + a[t.f][i].s, q.push({t.f, i, d[t.f][a[t.f][i].f]});
			for (int i = 0; i < b[xl].size(); i++){
				if ((a[b[xl][i].f].size() > 1 || b[xl][i].f == y) && b[xl][i].f != t.f && d[b[xl][i].f][xl] > t.d)
					d[b[xl][i].f][xl] = t.d, q.push({b[xl][i].f, find(b[xl][i].f, xl), t.d});
			}
		}
		ll minn = 1e18;
		for (int i = 0; i < a[y].size(); i++) minn = min(minn, d[y][a[y][i].f] + (ll)a[y][i].s);
		cout << minn + w[y] << endl;
	}
	return 0;
}
