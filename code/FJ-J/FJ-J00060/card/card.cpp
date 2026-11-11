// FJ-J00060
#include <iostream>
#include <string>
#define int long long
using namespace std;
int n, m, res[300005], a[500005];
int StringToInt(string s) {
	int res = 0;
	for (const auto& p : s) {
		res = res * 10 + (p - '0');
	}
	return res;
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		string pokers = "";
		for (int j = i; j < n; ++j) {
			if (pokers.find(to_string(a[j])) != string::npos) {
				pokers.erase(pokers.find(to_string(a[j])), pokers.size() - pokers.find(to_string(a[j])));
				pokers += to_string(a[j]);
				pokers += " ";
			} else {
				pokers += to_string(a[j]);
				pokers += " ";
			}
		}
		cout << pokers;
		string t = "";
		for (const auto& p : pokers) {
			if (p == ' ') {
				++res[StringToInt(t)];
				t = "";
			} else {
				t += p;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << res[i] << ' ';
	}
	return 0;
}

