#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
bool ton[300005];
int cnt[300005];
int fst[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool ok = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) ok = 0;
	}
	if(n * n <= 1e8) {
		for(int i = 1; i <= n; i ++) {
			stack <int> stk;
			memset(ton, 0, sizeof(ton));
			for(int j = i; j <= n; j ++) {
				if(ton[a[j]] == 1) {
					while(!stk.empty() && stk.top() != a[j]) {
						ton[stk.top()] = 0;
						stk.pop();
					}
				} else {
					stk.push(a[j]);
					ton[a[j]] = 1;
				}
			}
			while(!stk.empty()) {
				ans[stk.top()] ++;
				stk.pop();
			}
		}
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
	} else if(ok) {
		for(int i = 1; i <= n; i ++) {
			if(ton[a[i]] == 0) {
				ton[a[i]] = 1;
				fst[a[i]] = i;
			} else {
				cnt[a[i]] ++;
			}
		}
		for(int i = 1; i <= m; i ++) {
			if(ton[i] == 1) {
				ans[i] = fst[i] + cnt[a[i]];
			}
			cout << ans[i] << ' ';
		}
	} else {
		for(int i = 1; i <= n; i ++) {
			stack <int> stk;
			memset(ton, 0, sizeof(ton));
			for(int j = i; j <= n; j ++) {
				if(ton[a[j]] == 1) {
					while(!stk.empty() && stk.top() != a[j]) {
						ton[stk.top()] = 0;
						stk.pop();
					}
				} else {
					stk.push(a[j]);
					ton[a[j]] = 1;
				}
			}
			while(!stk.empty()) {
				ans[stk.top()] ++;
				stk.pop();
			}
		}
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
	}
	return 0;
}
