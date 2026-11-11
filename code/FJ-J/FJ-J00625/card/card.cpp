#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], tmpa[N];
int st[M], ans[N];
bool st1[N], A = true;
int main() {
	freopen("card.in","r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(i != 1 && a[i] < a[i - 1]) A = false;
	}
	if(n >= 1e5) {
		int l = a[1];
		for(int i = 1; i <= n; i ++) {
			if(a[i] != l) {
				st[a[i - 1]] = i - 1;
				l = a[i];
			}
		}
		st[a[n]] = n;
		for(int i = 1; i <= m; i ++) {
			cout << st[i] << " ";
		}
		return 0;
	}
	for(int i = 1; i <= n; i ++) {
		memset(st, 0, sizeof st);
		memset(st1, 0, sizeof st1);
		for(int j = 1; j <= n; j ++) {
			tmpa[j] = a[j];
		}
		stack<int> q;
		for(int j = i; j <= n; j ++) {
			if(st[tmpa[j]]) {
				int len = q.size();
				for(int k = 1; k <= len - st[tmpa[j]]; k ++)
					q.pop();
			}
			else {
				q.push(tmpa[j]);
				st[tmpa[j]] = q.size();
			}
		}
		for(int j = 0; j < q.size(); j ++) {
			auto s = q.top();
			if(!st1[s]) {
				ans[s] ++;
				st1[s] = 1;
			}
			q.pop();
		}
	}
	for(int i = 1; i <= m; i ++) {
		cout << ans[i] << " ";
	}
	return 0;
}
