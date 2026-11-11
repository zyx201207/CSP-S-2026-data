//GZ-J00116 贵阳市第一实验中学 姚彦竹
#include <bits/stdc++.h>
using namespace std;
int n, m; vector<string> v; string s;
bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() > b.size();
	return a > b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) cout << i << ' ';
	cout << endl << v[m];
	return 0;
}
