#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N], ans[N];
bool vis[N];
stack<int> q;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i ++) 
		cin >> a[i];
	
	for(int i = 1 ; i <= n ; i ++) {
		
		memset(vis, 0, sizeof(vis));
		for(int j = i ; j <= n ; j ++) {
			if(vis[a[j]] == 1) {
				while(q.top() != a[j]) {
					vis[q.top()] = 0;
					q.pop();
				}
			}
			else {
				q.push(a[j]);
				vis[a[j]] = 1;
			}
		}
		
		while(q.size()) {
			ans[q.top()] ++;
			q.pop();
		}
	}
	
	
	for(int i = 1 ; i <= m ; i ++) 
		cout << ans[i] << ' ';
		
	return 0;
}
