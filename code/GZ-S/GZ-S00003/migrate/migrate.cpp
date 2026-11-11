//GZ-S00003 贵阳市白云区华师一学校 殷浩然 
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for(int i = l; i <= r; i++)
#define dww(i, l, r) for(int i = l; i >= r; i--)
#define PII pair<int, int>
#define ub push_back
#define x first
#define y second
using namespace std;

const int N = 5e3 + 5;

int n, m;
int a[N];
int f[N][N];
int g[N][N];

void solve() {
	memset(f, 0x3f, sizeof f);
	memset(g, 0, sizeof g);
	cin >> n >> m;
	if (n >= 1000) return cout << 0 << endl, void();
	upp(i, 1, n) cin >> a[i];
	upp(i, 1, n) f[i][i] = 0, g[i][i] = 1;
	upp(i, 1, n) upp(j, i + 1, n) if (a[j] - a[i] <= m) f[i][j] = g[i][j] = 1;
	upp(len, 3, n) {
		upp(i, 1, n - len + 1) {
			int j = i + len - 1;
			upp(k, i + 1, j - 1) {
				if (a[k] - a[i] > m) break;
				int nf = f[i][k] + f[k][j];
				int ng = g[i][k] * g[k][j];
				if (nf < f[i][j]) f[i][j] = nf, g[i][j] = ng;
				else if (nf == f[i][j]) g[i][j] += ng;
			}
		}
	}
	int res = 0;
	upp(i, 1, n) upp(j, i + 1, n) if (g[i][j] == 2) res++;
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	
	return 0;
}

