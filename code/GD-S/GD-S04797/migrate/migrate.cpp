#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

const int N = 2e6 + 5;
const int mod = 998244353;
const int inf = 4e18;

int zh, T, n, d, ans;
int a[N], f[N], q[N], c[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> zh >> T;
	while (T--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ans = 0;
		if (zh <= 10){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++) f[j] = c[j] = 0;
				f[i] = c[i] = 1;
				for (int j = i + 1, h = i; j <= n; j++){
					while (h < j && a[j] - a[h] > d) h++;
					f[j] = f[h] + 1;
					c[j] = c[h] + (h + 1 < j && f[h + 1] == f[h]) * c[h + 1] + (h + 2 < j && f[h + 2] == f[h]) * c[h + 2];
					if (c[j] == 2) ans++;
				}
			}
			cout << ans << "\n";
		}
		else if (zh == 11 || zh == 12){
			for (int i = 1; i <= 1; i++){
				for (int j = 1; j <= n; j++) f[j] = c[j] = 0;
				f[i] = c[i] = 1;
				for (int j = i + 1, h = i; j <= n; j++){
					while (h < j && a[j] - a[h] > d) h++;
					f[j] = f[h] + 1;
					c[j] = c[h] + (h + 1 < j && f[h + 1] == f[h]) * c[h + 1] + (h + 2 < j && f[h + 2] == f[h]) * c[h + 2];
					if (c[j] == 2) ans += (n - j + 1);
				}
			}
			cout << ans << "\n";
		}
		else if (zh >= 15 && zh <= 18){
			int pos = 0;
			a[n + 1] = a[n + 2] = inf;
			for (int i = 1; i <= n; i++){
				if (a[i] - a[1] <= d && a[n] - a[i] <= d) pos = i;
			}
			vector<int> v;
			for (int i = pos + 2; i <= n; i++){
				if (a[i] - a[pos - 1] > d) v.pb(i);
			}
			for (int i = 1; i < pos; i++){
				if (a[pos + 1] - a[i] <= d && a[pos + 2] - a[i] > d) ans += (int)v.size();
			}
			v.clear();
			for (int i = 1; i <= pos - 2; i++){
				if (a[pos + 1] - a[i] > d) v.pb(i);
			}
			for (int i = pos + 1; i <= n; i++){
				if (a[i] - a[pos - 1] <= d && (pos == 1 || a[i] - a[pos - 2] > d)) ans += (int)v.size();
			}
			cout << ans << "\n"; 
		}
	}
	return 0;
}
