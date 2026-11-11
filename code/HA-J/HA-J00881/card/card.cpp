#include <bits/stdc++.h>
using namespace std;
int a[500010];
map<int,int> mp;
bool hav[300010];
int cnt[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int aaa = 1;aaa <= n;aaa++) {
		stack<int> stk;
		for (int i = 1;i <= m;i++) hav[i] = false;
		for (int i = aaa;i <= n;i++) {
			if (hav[a[i]]) {
				while (stk.top() != a[i]) {
					stk.pop();
				}
			} else stk.push(a[i]);
			hav[a[i]] = true;
		}
		while (!stk.empty()) {
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	for (int i = 1;i <= m;i++) cout << cnt[i] << " ";
	return 0;
}
