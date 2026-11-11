#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin)
#define fou(x) freopen(x, "w", stdout)
#define fre(x) fin(x".in"); fou(x".out");
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nti int
#define nit int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
int main() {
	fre("card")
	ios
	int n, m;
	cin >> n >> m;
	if (m == 2) {
		int cnt1 = 0, cnt2 = 0;
		For(i, 1, n) {
			int x;
			cin >> x;
			if (i == n && x == 1) cnt1 = n;
			else if (i == n && x == 2) cnt2 = n;
			else if (x == 1) cnt1++;
			else if (x == 2) cnt2++; 
		}
		cout << cnt1 << " " << cnt2 << endl;
		return 0;
	}
	if (n <= 5000) {
		vector<int>a(n + 1), vis(m + 1), now, cnt(m + 1);
		For(i, 1, n) cin >> a[i];
		For(i, 1, n) {
			now.clear();
			For(j, 1, m) vis[j] = 0;
			For(j, i, n) { 
				if (vis[a[j]]) {
					while (!now.empty() && now.back() != a[j]) vis[now.back()] = 0, now.pop_back();
					if (!now.empty()) now.pop_back();
				}
				vis[a[j]] = 1;
				now.push_back(a[j]);
			}
			for (auto k : now) cnt[k]++;
		}
		For(i, 1, m) cout << cnt[i] << " ";
	} else {
		vector<int>a(n + 1), cnt(m + 1);
		For(i, 1, n) cin >> a[i], cnt[a[i]] = i;
		For(i, 1, n) cout << cnt[a[i]] << " "; 
	}
}
