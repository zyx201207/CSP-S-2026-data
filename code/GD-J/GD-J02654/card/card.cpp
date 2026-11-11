#include<bits/stdc++.h>
using namespace std;
int n, m, a[500009], vis[300009];
long long ans[300009];
int main (  ) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		stack<int> st;
		for(int i = 1; i <= m; i++) vis[i] = 0;
		for(int j = i; j <= n; j++) {
			if(vis[a[j]] != 0) {
				while(!st.empty() && st.top() != a[j]) vis[st.top()] = 0, st.pop();
				if(!st.empty()) vis[st.top()] = 0, st.pop();
			}
			st.push(a[j]);
			vis[a[j]] = j;
		} 
		while(!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " "; 
	return 0;
}
