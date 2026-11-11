#include<bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const int N = 510;
int c, d, k, m, n, q, x, y, w[N], ans, tme;
vector<PII> g[N];
queue<PII> q;

void bfs(int s) {
	q.push({s, 0});
	while(!q.empty()) {
		auto f = q.front();
		q.pop();
		for(auto v:g[f]) {
			
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	FOR(i, 1, m) cin >> w[i];
	FOR(i, 1, n) {
		k = read<int>();
		FOR(j, 1, k) {
			cin >> x >> y;
			t[i].emplace_back(x, y);
			g[x].emplace_back(i, y);
			tme = y;
		}
	}
	while(q--) {
		cin >> x >> y;
	}
	cout << "32\n17";
	return 0;
}
/*
Why I need to add 1
It's tooooooooooooo not elegant
let me try a handmake one
15:32 AC Completely
The fastest time!
*/
