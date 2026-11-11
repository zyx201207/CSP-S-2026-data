#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
int b[N];
int ans;
void dfs(int now, int val, int tot) {
	if(tot == m) {
		ans = max(ans, val);
		return ;
	}
	if(now > n) return ;
	dfs(now + 1, val & a[now], tot + 1);
	dfs(now + 1, val, tot);
}
bool cmp(int x, int y) {
	int xx = x, yy = y;
	int z = 0, zz = 0;
	while(xx) z += (xx & 1), xx >>= 1;
	while(yy) zz += (yy & 1), yy >>= 1;
	return z ^ zz ? z > zz : x > y;
}
inline int read() {
	char ch;
	while(!isdigit(ch = getchar()));
	int res = ch ^ 48;
	while(isdigit(ch = getchar()))
		res = (res << 1) + (res << 3) + (ch ^ 48);
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i)
		a[i] = read();
	if(n <= 20) {
		for(int i = 1; i <= n; ++i) {
			memcpy(b, a, sizeof b);
			swap(b[1], b[i]);
			dfs(1, b[1], 0);
		}
		cout << ans;
	}
	else if(n <= 2000) {
		if(m == 1) {
			for(int i = 1; i <= n; ++i)
				ans = max(ans, a[i]);
			cout << ans;
		}
		else if(m == n) {
			ans = a[1];
			for(int i = 2; i <= n; ++i)
				ans &= a[i];
			cout << ans;
		}
		else {
			for(int i = 1; i <= n; ++i)
				for(int j = i + 1; j <= n; ++j)
					ans = max(ans, a[i] & a[j]);
			cout << ans;
		}
	}
	else {
		bool A = true;
		for(int i = 1; i <= n; ++i)
			A &= ((1 << (int)log2(a[i] + 1)) == a[i] + 1);
		bool C = true;
		for(int i = 1; i <= n; ++i)
			C &= (a[i] < 4);
		if(m == n - 1) {
			for(int i = 1; i <= n; ++i) {
				int pos = (i == 1 ? 2 : i - 1);
				int x = a[pos];
				for(int j = 1; j <= n; ++j)
					if(i ^ j && pos ^ j)
						x &= a[j];
				ans = max(ans, x);
			}
			cout << ans;
		}
		else if(A) {
			sort(a + 1, a + n + 1, greater<int>());
			cout << a[m];
		}
		else if(C) {
			int cnt3 = 0;
			for(int i = 1; i <= n; ++i)
				cnt3 += (a[i] == 3);
			if(cnt3 >= m) cout << 3;
			else {
				int cnt2 = 0;
				for(int i = 1; i <= n; ++i)
					cnt2 += (a[i] == 2);
				if(cnt3 + cnt2 >= m) cout << 2;
				else {
					int cnt1 = 0;
					for(int i = 1; i <= n; ++i)
						cnt1 += (a[i] == 1);
					if(cnt3 + cnt2 + cnt1 >= m) cout << 1;
					else cout << 0;
				}
			}
		}
		else {
			sort(a + 1, a + n + 1, cmp);
			ans = a[1];
			for(int i = 2; i <= m; ++i)
				ans &= a[i];
			cout << ans;
		}
	}
	return 0;
}//60
