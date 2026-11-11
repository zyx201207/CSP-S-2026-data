#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c, T, n, d, a[N], b[N], ans = 0;
int cnt = 0, Min = INT_MAX;
bool flag;
void dfs(int depth, int zd, int cur) {
	if(depth == zd + 1) {
		b[++cnt] = cur;
		if(cur == Min) flag = true;
		if(cur < Min) Min = cur, flag = false;
		return;
	}
	int x = depth + 1;
	while(d >= abs(a[x] - a[depth])) {
		dfs(depth + 1, zd, cur + abs(a[x] - a[depth]));
	}
	return;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	if(c == 11 || c == 12){
		while(T--) {
			ans = 0;
			cin >> n >> d;
			for(int i = 1;i <= n;i++) cin >> a[i];
			if(d < a[2] - a[1]) ans = 0;
			else {
				int many = d / (a[2] - a[1]);
				for(int i = d + 2;i <= n;i += 2) ans += 2;
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
