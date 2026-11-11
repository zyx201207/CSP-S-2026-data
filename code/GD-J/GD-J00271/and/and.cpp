#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans;
bool vis[N];
bool check(int x){
	int cnt = 0;
	for(int i = 1;i <= n;i ++) if(vis[i] && (a[i] & (1 << x)) == (1 << x)) cnt ++;
	return cnt >= m;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i], vis[i] = 1;
	for(int i = 30;i >= 0;i --){
		if(check(i)){
			ans += (1 << i);
			for(int j = 1;j <= n;j ++) if(vis[j] && (a[j] & (1 << i)) != (1 << i)) vis[j] = 0;
		}
	}
	cout << ans;
	return 0;
}
