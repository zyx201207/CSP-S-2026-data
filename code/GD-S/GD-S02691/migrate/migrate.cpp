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

int test_case, data_id;

void solution() {
	int n, d; cin >> n >> d;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> f(n + 1), g(n + 1);
	for(int i = 1; i <= n; i++) {
		f[i] = i == 1 ? 1 : f[i - 1];
		while(f[i] < n && abs(a[i] - a[f[i] + 1]) <= d) f[i]++;
	}
	for(int i = n; i >= 1; i--) {
		g[i] = i == n ? n : g[i + 1];
		while(g[i] > 1 && abs(a[i] - a[g[i] - 1]) <= d) g[i]--;
	}
	
	vector<int> c1(n + 1), d1(n + 1);
	c1[1] = 0, d1[1] = 0;
	for(int i = 1; i <= n; i++) {
		if(g[f[i]] == i && i < f[i]) c1[f[i]] += c1[i] + d1[i] + 1;
		if(g[f[i]] != i && i < f[i]) d1[f[i]]++;
	}
//	for(int i = 1; i <= n; i++) {
//		cout << c1[i] << " ";
//	}
	vector<int> c2(n + 1), d2(n + 1);
	c2[n] = 0, d2[n] = 0;
	for(int i = n; i >= 1; i--) {
		if(f[g[i]] == i && g[i] < i) c2[g[i]] += c2[i] + d2[i] + 1;
		if(f[g[i]] != i && g[i] < i) d2[g[i]]++;
	}
//	cout << "f:\n";
//	for(int i = 1; i <= n; i++) {
//		cout << f[i] << " ";
//	}
//	cout << "\n";
//	
//	cout << "g:\n";
//	for(int i = 1; i <= n; i++) {
//		cout << g[i] << " ";
//	}
//	cout << "\n";
//	cout << "c1:\n";
//	for(int i = 1; i <= n; i++) {
//		cout << c1[i] << " ";
//	}
//	cout << "\n";
//	cout << "c2:\n";
//	for(int i = 1; i <= n; i++) {
//		cout << c2[i] << " ";
//	}
//	cout << "\n";
//	cout << "d1:\n";
//	for(int i = 1; i <= n; i++) {
//		cout << d1[i] << " ";
//	}
//	cout << "\n";
//	cout << "d2:\n";
//	for(int i = 1; i <= n; i++) {
//		cout << d2[i] << " ";
//	}
//	cout << "\n";
	
	ll ans = 0;
	for(int i = 1; i < n; i++) {
//		cout << f[i] << " " << g[i + 1] << " " << c2[i] * c1[i + 1] << "\n";
		if(f[i] != i + 1 && g[i + 1] != i) ans += c2[i] * c1[i + 1];
//		vector<int> x = { i + 1 }, y = { i };
//		int cur = i + 1;
//		while(f[g[cur]] == cur && g[cur] < cur) cur = g[cur], x.emplace_back(cur);
//		cur = i;
//		while(g[f[cur]] == cur && cur < f[cur]) cur = f[cur], y.emplace_back(cur);
//		
//		cout << i << " " << i + 1 << "]:\n";
//		for(auto u : x) {
//			for(auto v : y) {
//				ans += 1ll * (d1[u] + (u != i)) * (d1[v] + (v != i + 1));
//				cout << u << " " << v << ") " << (d1[u] + (u != i)) * (d1[v] + (v != i + 1)) << "\n";
//			}
//		}
	}
	cout << ans << "\n";
}
void prework() {}

int main() {
	fileIO("migrate");
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int test_num = 1; cin >> data_id >> test_num;
	prework();
	for (test_case = 1; test_case <= test_num; test_case++) solution();
	return 0;
}
