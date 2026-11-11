#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
const int N = 2e6 + 5;
int C, T, n, d, a[N], f[N], g[N], s[N], s1[N], L[N], R[N]; 
vector <int> v[5005];
int dis[5005][5005], c[5005][5005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> T;
	while(T--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if(n <= 5000) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					dis[i][j] = 0;
					c[i][j] = 0;
				}
				v[i].clear();
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j < i; j++) {
					if(abs(a[i] - a[j]) <= d) {
						v[i].push_back(j);
						v[j].push_back(i);
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				queue <int> q;
				q.push(i);
				dis[i][i] = 1;
				c[i][i] = 1;
				while(!q.empty()) {
					int x = q.front();
					q.pop();
					for(int j = 0; j < v[x].size(); j++) {
						int y = v[x][j];
						if(!dis[i][y]) {
							dis[i][y] = dis[i][x] + 1;
							c[i][y] = c[i][x];
							q.push(y);
						}
						else if(dis[i][y] == dis[i][x] + 1) {
							c[i][y]++;
						}
					}
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j < i; j++) {
					if(c[i][j] == 2) {
						ans++;
					}
				}
			}
			cout << ans << '\n';
			continue ;
		} 
		for(int i = 1; i <= n; i++) {
			f[i] = 1, g[i] = 1, s[i] = 0, s1[i] = 0, L[i] = R[i] = i;
		}
		f[n + 1] = g[n + 1] = 0, L[n + 1] = R[n + 1] = 0;
		int l = 1;
		s[1] = 1;
		for(int i = 2; i <= n; i++) {
			while(a[i] - a[l + 1] > d) l++;
			if(a[i] - a[l] > d) l++;
			l = min(l, n);
			if(l == i) f[i] = 1;
			if(l == i - 1) f[i] = f[i - 1] + 1;
			else {
				f[i] = i - l;
			}
			s[i] = s[i - 1] + f[i];
			L[i] = l;
		}
		l = n;
		s1[n] = 1;
		for(int i = n - 1; i >= 1; i--) {
			while(a[l - 1] - a[i] > d) l--;
			if(a[l] - a[i] > d) l--;
			l = max(l, 1ll);
			if(l == i) g[i] = 1;
			if(l == i + 1) g[i] = g[i + 1] + 1;
			else {
				g[i] = l - i;
			}
			R[i] = l;
		}
		for(int i = 0; i <= n + 1; i++) s[i] = s1[i] = 0;
		for(int i = 1; i <= n; i++) s[i] = s[i - 1] + f[i];
		for(int i = n; i >= 1; i--) s1[i] = s1[i + 1] + g[i];
		int ans = 0;
		for(int i = 2; i <= n - 1; i++) {
			if(a[i + 1] - a[i - 1] <= d && a[i + 2] - a[i] <= d) {
				int cnt = i + 2;
				ans += (f[i - 1] - max(0ll, i - 1 - L[i])) * (g[cnt] - max(0ll, R[i + 1] - cnt));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
6 1200000000
-1000000000 -600000000 -200000000 200000000 600000000 1000000000
*/ 
