#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
bool vis[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	stack<int> s;
	int x = 1;
	while(x <= n){
		memset(vis, 0, sizeof(vis));
		for (int i = x; i <= n; i++){
			if (!vis[a[i]]) {
				s.push(a[i]);
				vis[a[i]] = 1;
			}else {
				int k = s.top();
				while(k != a[i]){
					s.pop();
					k = s.top();
				}
				s.pop();
				s.push(a[i]);
			}
		}
		for (int i = 0; i <= s.size(); i++){
			int au = s.top();
			ans[au]++;
			s.pop();
		}
		x++;
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
