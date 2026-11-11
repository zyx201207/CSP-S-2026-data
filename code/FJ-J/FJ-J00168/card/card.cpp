#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n = 0, m = 0;
int a[N];
vector<int> s[N];
int w[N];
int ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--) {
		int tt = w[a[i]];
		if (!w[a[i]]) {
			w[a[i]] = i;
		}
//		while (w[tt] && tt) {
//			int ttt = tt;
//			tt = w[ttt + 1];
//		}
		if (tt) {
			s[i] = s[tt + 1];
			s[i].push_back(a[i]);
		} else {
			s[i] = s[i + 1];
			s[i].push_back(a[i]);
		}
		for (int j = 0; j < s[i].size(); j++) {
			ans[s[i][j]]++;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < s[i].size(); j++) {
//			cout << s[i][j] << " ";
//		}
//		cout << "\n";
//	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
