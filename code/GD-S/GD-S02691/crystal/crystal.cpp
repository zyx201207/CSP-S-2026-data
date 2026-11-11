#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int; using ll = long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template<typename T, typename U>
bool chkmin(T &a, const U &b) { return (b < a ? (a = b, true) : false); }
template<typename T, typename U>
bool chkmax(T &a, const U &b) { return (b > a ? (a = b, true) : false); }
void fileIO(const string &x) { freopen((x + ".in").c_str(), "r", stdin); freopen((x + ".out").c_str(), "w", stdout); }
mt19937_64 gen(random_device{}());

int test_case;

void solution() {
	int n; ll m; cin >> n >> m;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	ll ans = 0;
	vector<ll> s(n + 1); 
	for(int i = 1; i <= n; i++) {
		ll tot = m, cnt = 1;
		s[i] = s[i - 1] + a[i];
		int l = 0, r = i;
		while(l + 1 != r) {
			int mid = (l + r) / 2;
			int len = i - mid;
			// [mid, i - 1]
			if (len * a[i] - (s[i - 1] - s[mid - 1]) <= m) r = mid;
			else l = mid;
		}
//		for(int j = i - 1; j >= 0; j--) {
//			if(tot >= a[i] - a[j]) {
//				tot -= a[i] - a[j];
//				cnt++;
//			}
//		}
//		cout << cnt << "\n";
		chkmax(ans, i - r + 1);
	}
	cout << ans << "\n";
}
void prework() {}

int main() {
	fileIO("crystal");
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int test_num = 1; // cin >> test_num;
	prework();
	for (test_case = 1; test_case <= test_num; test_case++) solution();
	return 0;
}
