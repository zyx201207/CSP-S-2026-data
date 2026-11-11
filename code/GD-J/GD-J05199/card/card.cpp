#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],pre[N],lst[N],ans[N];
//vector<int> g[N];
bool vis[N];
int dp[N],cnt;

struct node {
	int val,t;
};
 

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
//		pre[i] = lst[a[i]];
//		nxt[lst[a[i]]] = i;
		lst[a[i]] = i;
	}
	if (n <= 5005) {
		stack<int> st;
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				while (!st.empty() && vis[a[j]]) {
					vis[st.top()] = 0;
					st.pop();
				}
				st.push(a[j]);
				vis[a[j]] = 1;
			}
			while (!st.empty()) {
	//			cout << st.top() << ' ';
				ans[st.top()] ++;
				vis[st.top()] = 0;
				st.pop();
			}
	//		cout << endl;
		}
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
	}else {
		stack<node> st;
		for(int i = n; i >= 1; i --) {
			while (!st.empty() && st.top().t < lst[a[i]]) {
				node x = st.top();
				vis[x.val] = 0;
				ans[x.val] += x.t - i;
				st.pop();
			}
			if (!vis[a[i]]) st.push({a[i],i});
			vis[a[i]] = 1;
		} 
		while (!st.empty()) {
			node x = st.top();
			st.pop();
			ans[x.val] += x.t;
		}
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
	}
	return 0;
}

