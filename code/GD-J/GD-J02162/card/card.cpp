#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010];
bool vis[500010];
int ans[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) flag = 0; 
	}
	if(flag) {
		int lst = a[1];
		for(int i = 1; i <= n; i ++) {
			if(a[i] != lst) cout << (i - 1) << ' ', lst = a[i];
		}
		cout << n;
		return 0;
	}
	for(int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		stack<int> st;
		for(int j = i; j <= n; j ++) {
			if(vis[a[j]] == 1) {
				vis[a[j]] = 0;
				while(st.size() && st.top() != a[j]) vis[st.top()] = 0, st.pop();
				if(st.size()) st.pop();
			}
			vis[a[j]] = 1;
			st.push(a[j]);
		}
		while(st.size()) ans[st.top()] ++, st.pop();
	}
	for(int i = 1; i <= m; i ++) cout << ans[i] << ' ';
	return 0;
}
/*
·ÉÓ©ÆË»ð£¬ÏòËÀ¶øÉú£¡ 
*/
