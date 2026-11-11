#include <bits/stdc++.h>
using namespace std;

#define ll long long 


#define cout fout
#define cin fin
ifstream fin("migrate.in");
ofstream fout("migrate.out");

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int c, t;

ll n, d;

void bf() {
	vector <ll> vx(n + 1);
	vector <vector <int> > ve(n + 1);
	for (int i = 1; i <= n; i++) cin >> vx[i];
	int r = 1;
	for (int i = 1; i <= n; i++) {
		while (r + 1 <= n && vx[r + 1] - vx[i] <= d) r++;
		for (int j = i + 1; j <= r; j++) {
			ve[i].push_back(j);
//			cout << i << ' ' << j << '\n';
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		vector <ll> dis(n + 1, inf), cnt(n + 1);
		queue<int> q;
		q.push(i);
		dis[i] = 0;
		cnt[i] = 1;
		while (q.size()) {
			auto now = q.front(); q.pop();
			for (auto nxt : ve[now]) {
				if (dis[now] + 1 <= dis[nxt]) {
					if (dis[now] + 1 < dis[nxt]) {
						q.push(nxt);
					}
					cnt[nxt] += cnt[now];
					if (cnt[nxt] >= inf) cnt[nxt] = inf;
					dis[nxt] = dis[now] + 1;
				}
			}
		}
//		for (int j = 1; j <= n; j++) {
//			if (cnt[j] == 2) {
//				cout << i << ' ' << j << ' ' << dis[j] << '\n';
//			}
//		}
		for (auto j : cnt) {
			ans += j == 2;
		}
	}
	cout << ans << '\n';
	

}

void solve() {
	cin >> n >> d;
	
	if (n <= 5000) {
		bf();
		return;
	}
	
	vector <ll> vx(n + 1), cnt(n + 1), lc(n + 1), rc(n + 1);
	for (int i = 1; i <= n; i++) cin >> vx[i];
	vx.push_back(LLONG_MAX);
	
	{
		int r = 1;
		for (int l = 1; l <= n; l++) {
			while (r + 1 <= n && vx[r + 1] - vx[l] <= d) r++;
//			[l, r]
			if (l + 1 == r) continue;
			if (l > 1 && l < n && vx[l + 1] - vx[l - 1] > d) {
				rc[l] = r - l;
			}
			if (r > 1 && r < n && vx[r + 1] - vx[r - 1] > d) {
				lc[r] = r - l;
			}
		}
	}	
	
	{
		int l = 1, r = 2;
		while (r <= n) {
			if (vx[r] - vx[r - 1] > d) {
				int mxl = *max_element(lc.begin() + l, lc.begin() + r);
				int mxr = *max_element(rc.begin() + l, rc.begin() + r);
				for (int i = l; i < r; i++) {
					cnt[i] = r - l;
					lc[i] = mxl;
					rc[i] = mxr;
				}
				l = r;
			} else if (r > 2 && vx[r] - vx[r - 2] <= d) {
				int mxl = *max_element(lc.begin() + l, lc.begin() + r - 1);
				int mxr = *max_element(rc.begin() + l, rc.begin() + r - 1);
				for (int i = l; i <= r - 2; i++) {
					cnt[i] = r - l - 1;
					lc[i] = mxl;
					rc[i] = mxr;
				}
				cnt[r - 1] = 1;
				l = r;
			}
			
			r++;
		}
		for (int i = l; i < r; i++) {
			cnt[i] = r - l;
		}
		
	}
	

	
//		for (int i = 1; i <= n; i++) {
//			cout << cnt[i] << ' ';
//		}
//		cout << '\n';	
//		for (int i = 1; i <= n; i++) {
//			cout << lc[i] << ' ';
//		}
//		cout << '\n';
//		for (int i = 1; i <= n; i++) {
//			cout << rc[i] << ' ';
//		}
//		cout << '\n';
	
	ll ans = 0, sum = 0;
	int r = 1, r2 = 1, r3 = 1;
	
	
	// i ...
	for (int i = 1; i <= n; i++) {
		while (r + 1 <= n && vx[r + 1] - vx[i] <= d) r++;
		if (r - 2 < i) continue;
		while (r2 <= n && vx[r2] - vx[r - 2] <= d) {
			sum -= cnt[r2];	// vx[r2] - vx[r - 2] > d
			r2++;
		}
		while (r3 <= n && vx[r3] - vx[r - 1] <= d) {
			sum += cnt[r3];	// vx[r3] - vx[r - 1] > d
			r3++;
		}
		if (r2 < r3) ans += (lc[i] + cnt[i]) * (rc[r3 - 1] + sum);
//		cout << lc[i] << ' ' << cnt[i] << '\n';
//		cout << lc[i] + cnt[i] << ' ' << rc[r3 - 1] + sum << ' ' << i << ' ' << r << ' ' << r2 << ' ' << r3 << '\n';
	}
	
	
	cout << ans << '\n';
	
}

signed main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	
} 


/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
-3 0 2 3 4

0 1
7 8
1 2 9 10 11 12 20

*/
