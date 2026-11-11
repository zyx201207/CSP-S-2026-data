#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
queue<int> q;
int ans[500005] = {0}; 
int d[500005], idx = 0, hail, tail;
int main() {
	freopen("card.in", "w", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	int key[500005] = {0};
	bool ok[500005] = {0};
	for(int i = 1;i <= n;i ++) {
		for(int j = i;j <= n;j ++) {
			if(!ok[a[i]]) {
				q.push(a[i]);
				ok[a[i]] = true;
				key[a[i]] = ++ idx;
			} else {
				for(int i = 1;i <= key[a[i]];i ++) {
					q.pop();
				} 
			}
		}
		while(!q.empty()) {
			int x = q.front();
			q.pop();
		}
	}
	for(int i = 1;i <= m;i ++) {
		cout << ans[i] << " ";
	}
	return 0;
}
