#include <bits/stdc++.h>
using namespace std; 
#define int long long

int n, m, a[500010];
struct node {
	int pre, val, nxt;
};
unordered_map<int, vector<int>> mp; unordered_map<int, int> ans;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	bool flag1 = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i - 1] > a[i]) flag1 = false;
	}
	if(n <= 500) {
		for(int i = 1; i <= n; i++) {
			stack<int> st;
			for(int j = i; j <= n; j++) {
				stack<int> t = st; bool flag = 0;
				while(!st.empty()) {
					int x = st.top(); st.pop();
					if(x == a[j]) { flag = true; break;}
				}
				if(!flag) st = t;
				st.push(a[j]);
			} 
			while(!st.empty()) {
				int x = st.top(); st.pop();
				ans[x]++;
			}
		}
		for(int i = 1; i <= m; i++) cout << ans[i] << " ";
		return 0;
	}
	if(flag1) {
		vector<int> vis(n + 1);
		for(int i = 1; i <= n; i++) {
			
		}
		for(int i = 1; i <= m; i++) cout << upper_bound(a + 1, a + n + 1, i) - a - 1 << " ";
		return 0;
	}
	for(int i = 1; i <= n; i++) {
			stack<int> st;
			for(int j = i; j <= n; j++) {
				stack<int> t = st; bool flag = 0;
				while(!st.empty()) {
					int x = st.top(); st.pop();
					if(x == a[j]) { flag = true; break;}
				}
				if(!flag) st = t;
				st.push(a[j]);
			} 
			while(!st.empty()) {
				int x = st.top(); st.pop();
				ans[x]++;
			}
		}
		for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}

