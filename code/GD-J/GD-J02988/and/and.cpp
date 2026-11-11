#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, m, a[MAXN];
bool vis[MAXN];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int p, ans = 0;
	fill(vis + 1, vis + 1 + n, 1);
	for(int k = 30; k >= 1; k--){
		p = (1 << (k - 1));
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] & p && vis[i]) cnt++;
		}
		if(cnt < m) continue;
		for(int i = 1; i <= n; i++){
			if(!(a[i] & p)){
				vis[i] = 0;
			}
		}
		ans |= p;
	}
	cout << ans;
	return 0;
}
