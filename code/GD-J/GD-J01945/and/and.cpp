#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 66;
int n, m;
int a[N], s[50], vis[N][50];
int b[N][50], cnt, tmp = 1;
int ans;

inline int read() {
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	
	return x;
}

void solve(int x) {
	int k = a[x];
	int i = 1;
	while(k) {
		if(k & 1) vis[x][i] = 1, s[i] ++;
		i ++; k >>= 1ll;
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
		solve(i);
	}
	
	for(int i = 40; i >= 1; i --) {
		if(s[i] < m) continue;
		if(!cnt) {
			for(int j = 1; j <= n; j ++) {
				if(vis[j][i]) {
					b[++ cnt][tmp] = j;
				}
			}
			
			ans = ans + (1ll << (i - 1));
		} else {
			int now = 0;
			for(int j = 1; j <= cnt; j ++) {
				now += (vis[b[j][tmp]][i]);
			}
			
			if(now >= m) {
				ans = ans + (1ll << (i - 1));
				tmp ++;
				
				int len = cnt;
				cnt = 0;
				for(int j = 1; j <= len; j ++) {
					if(vis[b[j][tmp - 1]][i]) {
						b[++ cnt][tmp] = b[j][tmp - 1];
					}
				}
			}
		}
		
//		for(int j = 1; j <= cnt; j ++) {
//			cout << b[j][tmp] << ' ';
//		}
//		cout << '\n';
	}
	
	cout << ans;
	return 0;
}
