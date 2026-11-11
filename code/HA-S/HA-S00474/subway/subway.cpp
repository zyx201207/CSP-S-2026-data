#include <bits/stdc++.h>
using namespace std;

const int M = 5e5 + 5;
const int N = 505;

using ll = long long;
using pll = pair<ll, ll>;

unordered_map<string, short> mp = 
{
	{"kou", 0},
	{"hall", 1},
	{"sub", 2}
};

struct sub {
	ll k;
	vector<int> a, t;
} ss[N];

struct Node {
	string at_where;
	ll walked;
	ll sta_num;
	ll on_sub, on_pos;

	Node (string aw, ll w, ll sn, ll os, ll op) : at_where(aw), walked(w), sta_num(sn), on_sub(os), on_pos(op) {}
};

vector<pll> mp_sub[M]; // based-1
ll ww[M];
ll dis[M][3];
ll c, m, n, d, q;

struct cmp {
	bool operator () (Node a, Node b) {
		if (a.walked != b.walked) return a.walked > b.walked;
		if (a.at_where == "hall" && b.at_where == "sub") return true;
		return false;
	}
};

ll Dijistra (ll s, ll t) {
	priority_queue<Node, vector<Node>, cmp> pq;
	memset(dis, 0x3f, sizeof(dis));
	pq.push(Node("kou", 0, s, -1, -1));

	while (pq.size()) {
		Node u = pq.top();
		pq.pop();

		if (dis[u.sta_num][mp[u.at_where]] != 0x3f3f3f3f) continue;
		if (u.sta_num == t && u.at_where == "kou") return u.walked;

		if (u.at_where == "kou") {
			pq.push(Node("hall", ww[u.sta_num], u.sta_num, -1, -1));
			continue;
		}
		if (u.at_where == "hall") {
			pq.push(Node("kou", u.walked + ww[u.sta_num], u.sta_num, -1, -1));
			for (ll i = 0; i < mp_sub[u.sta_num].size(); i++) {
				ll subs = mp_sub[u.sta_num][i].first;
				ll pos = mp_sub[u.sta_num][i].second;
				pq.push(Node("sub", u.walked + ss[subs].t[pos - 1], u.sta_num, subs, pos));
			}
			continue;
		}
		if (u.on_pos < ss[u.on_sub].k) pq.push(Node("sub", u.walked, ss[u.on_sub].a[u.on_pos], u.on_sub, u.on_pos + 1));
		pq.push(Node("hall", u.walked + ss[u.on_sub].t[u.on_pos - 1], u.on_pos - 1, -1, -1));
	}
}

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= m; i++) cin >> ww[i];
	for (int i = 1; i <= n; i++) {
		cin >> ss[i].k;
		for (int j = 1; j <= ss[i].k; j++) {
			ll aij, tij;
			cin >> aij >> tij;
			ss[i].a.push_back(aij);
			ss[i].t.push_back(tij);
			mp_sub[aij].push_back({i, j});
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << Dijistra(x, y) << "\n";
	}
	return 0;
}

