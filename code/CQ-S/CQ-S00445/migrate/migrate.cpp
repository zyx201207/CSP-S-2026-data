#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define db double
#define i128 __int128_t

#define endl "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

using namespace std;

template <class T> void cmax (T &a, T b) {a = max(a, b); }
template <class T> void cmin (T &a, T b) {a = min(a, b); }

const int inf = 1e9;
const ll INF = 2e18;
const int mod = 1e9 + 7;
const db eps = 1e-6;
const int maxn = 20005;
const int N = 1e6 + 7;

vector<int> back(maxn + 1);
vector<vector<pii>> edges(maxn + 1);
vector<int> du(maxn, 0);
vector<map<int, int>> flag(maxn);

void init (int p, int cl, int cr) {
    if (cl == cr) {
        back[cl] = p;
        return;
    }
    int mid = (cl + cr) >> 1, lc = p << 1, rc = lc | 1;
    edges[lc].push_back({p, 0}), edges[rc].push_back({p, 0});
    init(lc, cl, mid), init(rc, mid + 1, cr);
}

void modify (int p, int cl, int cr, int l, int r, int u) {
    if (l > r) return;
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r) {
        // cerr << p << ' ' << back[u] << endl;
        edges[p].push_back({back[u], 1});
        return;
    }
    int mid = (cl + cr) >> 1, lc = p << 1, rc = lc | 1;
    modify(lc, cl, mid, l, r, u), modify(rc, mid + 1, cr, l, r, u);
}

void dfs (int u) {
    for (auto v : edges[u]) {
    	// cerr << u << ' ' << v.first << endl;
    	if (!flag[v.first].count(u)) du[v.first] += 1;
    	flag[v.first][u] += 1;
        dfs(v.first);
    }
}

void solve () {
	for (int i = 0; i < maxn; i++) edges[i].clear();
	
//	cerr << "---------------------" << endl;
	
    ll n, d; cin >> n >> d;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    init(1, 1, n);
    
    // cerr << "----------------" << endl;

    vector<pii> dp(n << 2, {inf, 1});

    int r = 1;
    for (int i = 1; i <= n; i++) {
        while (r < n && a[r + 1] - a[i] <= d) r += 1;
        modify(1, 1, n, i + 1, r, i);
    }

//	cerr << "ok" << endl;

    // cerr << "--------------" << endl; 

    int ans = 0;

    // for (int i = 1; i <= n; i++) cerr << back[i] << ' ';
    // cerr << endl;

    for (int i = 1; i <= n; i++) {
    	// cerr << i << "-----" << endl; 
        for (int j = 1; j < (n << 2); j++) du[j] = 0;
        for (int j = 1; j < (n << 2); j++) flag[j].clear();
        dfs(back[i]);
        // for (int j = 1; j < (n << 2); j++) cerr << du[j] << ' ';
        // cerr << endl;

        // cerr << "------------" << endl;

        for (int j = 1; j < (n << 2); j++) dp[j] = {inf, 1};
        dp[back[i]] = {0, 1};
        queue<int> q; q.push(back[i]);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            // cerr << "u " << u << ' ' << dp[u].first << ' ' << dp[u].second << endl;
            for (auto tmp : edges[u]) {
                auto v = tmp.first, w = tmp.second;
                if (dp[v].first == dp[u].first + w) dp[v].second += dp[u].second;
                if (dp[v].first > dp[u].first + w) dp[v] = {dp[u].first + w, dp[u].second};
                if (!--du[v]) q.push(v);
            }
        }

		// for (int j = 1; j <= i; j++) cerr << dp[back[j]].first << ' ' << dp[back[j]].second << endl;

        for (int j = 1; j <= i; j++) if (dp[back[j]].second == 2) {
        	// cerr << "++ans " << j << endl;
        	ans += 1;
		}
        
//        cerr << ans << endl; 
    }

    cout << ans << endl;
} 

int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c, T = 1;
    cin >> c >> T;

    while (T--) {
        solve();
    }

    return 0;
}
