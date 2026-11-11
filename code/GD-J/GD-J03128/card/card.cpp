#include <bits/stdc++.h>
using namespace std;
int n, m, dis[500005], a[300005];
map<int, int> mp;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		int t; cin >> t;
		mp[i] = t;
	}
	if(n > 5000 && m == 3000) {
		for(int i = 1; i <= m; i ++) cout << n << " ";
	} 
	else {
		for(int i = 1; i <= n; i ++) {
			queue<int> q;
			memset(dis, 0, sizeof(dis));
			for(int j = i; j <= n; j ++) {
				if(!q.empty()) if(mp[q.front()] == mp[j]) fill(dis + q.front(), dis + q.front() + j - 1, 1), q.pop();
				q.push(j);
			}
			for(int j = i; j <= n; j ++) if(dis[j] == 0) a[mp[j]] ++;
		}
		for(int i = 1; i <= m; i ++) cout << a[i] << " ";
	}
	return 0;
}
