#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define ft first
#define sd second
#define eb emplace_back
#define pb push_back
template<class T> inline void gmax(T& x, T y) {if (x < y) x = y;}
template<class T> inline void gmin(T& x, T y) {if (x > y) x = y;}
const int N = 5e5 + 10, M = 5e6 + 10, inf = 0x3f3f3f3f, mod = 998244353;
const ll linf = 0x3f3f3f3f3f3f3f3f;
inline void filo(string in, string out, int op = 3) {if (op & 1) freopen((in + ".in").c_str(), "r", stdin); if (op & 2) freopen((out + ".out").c_str(), "w", stdout);}
int n, ans = 1;
ll m, a[N], sum, s[N];
inline ll get(int l, int r) { // l~r È«±äÎª r 
	return (r - l + 1) * a[r] - s[r] + s[l - 1];
}


int main() {
	filo("crystal", "crystal");
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (get(mid, i) <= m) r = mid - 1;
			else l = mid + 1; 
		}
		gmax(ans, i - r);
	}
	cout << ans << '\n';
	return 0;
}


