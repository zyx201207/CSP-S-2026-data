#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 2e6+7, M = 2e5+7;
ll a[N];
ll d = 0;
int n;

namespace sub1 {
	int f[N], c[N];
	int ans = 0;
	int calc(int x) {
		for (int i = x; i <= n; i++) f[i] = INT_MAX, c[i] = 0;
		f[x] = 0;
		for (int i = x; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (llabs(a[i] - a[j]) > d) break;
				if (f[j] > f[i] + 1) {
					f[j] = f[i] + 1;
					c[j] = 1;
				}
				else if (f[j] == f[i] + 1) c[j]++;
	//			cout << -1 << endl;
			}
		}
//		for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i==n];
//		for (int i = 1; i <= n; i++) cout << c[i] << " \n"[i==n];
		int ans = 0;
		for (int i = x; i <= n; i++) {
			ans += (c[i] == 2);
		}
		return ans;
	}
	void solve() {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
//			f[i] = INT_MAX;
		}
		for (int i = 1; i <= n; i++) {
			ans += calc(i);
		}
		cout << ans << endl;
	} 
}

namespace sub2 {
	int f[N], c[N];
	void solve() {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f[i] = INT_MAX, c[i] = 0;
		}
		f[0] = 0;
		f[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (llabs(a[i] - a[j]) > d) break;
				if (f[j] > f[i] + 1) {
					f[j] = f[i] + 1;
					c[j] = 1;
				}
				else if (f[j] == f[i] + 1) c[j]++;
	//			cout << -1 << endl;
			}
		}
		for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += (c[i] == 2);
		}
		cout << ans << endl;
	}
	
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int tid, T;
	cin >> tid >> T;
	while (T--) {
		sub1::solve();
	}
	return 0;
}
