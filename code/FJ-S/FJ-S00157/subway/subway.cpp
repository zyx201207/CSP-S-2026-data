#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 10;
const int maxn = 500 + 10;
int n, m, d, q;
int w[maxm];
int k[maxn];
vector <int> b[maxn];
vector <int> h[maxn];
vector <int> a[maxn];
vector <int> t[maxn];
int x, y;
set <int> went[maxn];
int ans = 0;
void dfs (int step, int nol, int val){
	cout << step << " " << nol << endl;
	if (step == y){
		ans = min (ans, val);
		return;
	}
	if (went[step].count (nol)) return;
	went[step].insert (nol);
	int xv = 0;
	for (int i = 0; i < b[step].size(); i++){
		if (i == nol){
			xv = h[step][i];
			break;
		}
	}
	for (int i = 0; i < b[step].size(); i++){
		if (b[step][i] == nol){
			break;
		}
		dfs (step, b[step][i], val + h[step][i] + xv);
	}
	for (int i = 1; i < k[nol]; i++){
		if (a[nol][i] == step)
			dfs (a[nol][i + 1], nol, val);
	}
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	int c;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n ;i++){
		cin >> k[i];
		a[i].push_back (0);
		t[i].push_back (0);
		for (int j = 1; j <= k[i]; j++){
			a[i].push_back (0);
			t[i].push_back (0);
			cin >> a[i][j] >> t[i][j];
			b[a[i][j]].push_back (i);
			h[a[i][j]].push_back (t[i][j]);
		}
	}
	while (q--){
		cin >> x >> y;
		for (int i = 1; i <= n; i++){
			went[i] = set <int> ();
		}
		ans = 0x3f3f3f3f;
		for (int i : h[x])
			dfs (x, i, w[x] + w[y]);
		cout << ans << "\n";
	}
	cout << flush;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
//Can I have 1=? Is it possible? Can I get it?
