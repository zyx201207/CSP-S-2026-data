//GZ-J00116 贵阳市第一实验中学 姚彦竹
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int n, m, c[(int)5e5+10], ans[(int)3e5+10];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int mp[(int)3e5+10];
	stack<int> sta;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (mp[c[j]] != i) {
				mp[c[j]] = i;
				sta.push(c[j]);
			} else {
				while (sta.top() != c[j]) {
					mp[sta.top()] = 0;
					sta.pop();
				}
			}
		}
		while (!sta.empty()) {
			ans[sta.top()]++;
			sta.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
