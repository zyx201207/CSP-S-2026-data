#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int N = 5000 + 5;


int c, t;
ll a[N];
ll d;
int n;
pair<ll, int> kkk[N][N];

void dfs(int u, ll sum, int uuu) {
//	if (uuu == 1 && u == 2) cout << kkk[uuu][u].second << endl;
//			cerr << u << " " << uuu << " " << sum << " 12312312312312" << endl;
	if (kkk[uuu][u].first == sum) {
		kkk[uuu][u].second++;
	} else if (kkk[uuu][u].first > sum) {
		kkk[uuu][u].first = sum;
		kkk[uuu][u].second = 1;
	} else if (kkk[uuu][u].first == 0) {
		kkk[uuu][u].first = sum;
		kkk[uuu][u].second = 1;
	}
//	int id = upper_bound(a + 1, a + 1 + n, a[u] + d) - a - 1;
	for (int i = u + 1; i <= n; i++) {
		if (a[u] + d < a[i]) break;
		dfs(i, sum + 1, uuu);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				kkk[i][j] = make_pair(0, 0);
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			dfs(i, 0, i);	
			for (int j = i + 1; j <= n; j++) {
//				cout << i << " " << j << endl
//				cerr << i << " " << j << " " << kkk[i][j].first << " " << kkk[i][j].second << endl;
				ans += (kkk[i][j].second == 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
