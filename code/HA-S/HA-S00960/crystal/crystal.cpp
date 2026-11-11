#include <bits/stdc++.h>
#define int long long

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int maxn = 5e5 + 10;

int n, m;

int a[maxn];

bool cmp(int x, int y) {
	return x < y;
}

int ans;

void dfs(int r, int num, int ex) {
	for(int i = 1;i <= n; i++) {
		if(a[r] <= a[i] && i != r) {
			if(a[i] - a[r] <= ex) {
				num++;
				ans = max(ans, num);
				ex  = ex - a[i] + a[r];
				int xx = a[i];
				int yy = a[r];
				a[r] = a[i] * 2;
				a[i] = LLONG_MAX;
				
				dfs(r, num, ex);
				
				num--;
				a[i] = xx;
				a[r] = yy;
				ex = ex + a[i] - a[r];
			}
		}
		else continue;
	}
	return ;
}

signed main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for(int i = 1; i <= n; i++) {
		dfs(i, 0, m);
	}
	
	cout << ans + 1;
	return 0;
}
