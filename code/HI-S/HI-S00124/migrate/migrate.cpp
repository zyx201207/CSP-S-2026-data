#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int read() {
	int x=0,f=1;char chr=getchar();
	while (chr<'0'||'9'<chr){if(chr=='-')f=-f;chr=getchar();}
	while ('0'<=chr&&chr<='9'){x=x*10+chr-'0';chr=getchar();}
	return x*f;
}
const int N = 2e6 + 10;
int c,T;
int n,d; 
int x[N];
int f[N],g[N]; // 到达次数，方案数 
int val[N]; // 到达次数为i的方案数之和 
int solve() {
	n = read(),d = read();
	for (int i = 1; i <= n; i++) {
		x[i] = read();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 0,g[i] = 1;
		val[0] = 1;
		for (int j = i + 1,k = i; j <= n; j++) {
			if (x[j - 1] + d < x[j]) break;
			while (x[k] + d < x[j]) {
				val[f[k]] -= g[k];
				k++;
			}
			f[j] = f[k] + 1;
			g[j] = min(val[f[k]],3ll);
//			cout << "i = " << i << " j = " << j << " k = " << k << " f[j] = " << f[j] << " g[j] = "<<g[j] <<"\n";
			if (f[j] != f[j - 1]) val[f[j]] = 0;
			val[f[j]] += g[j];
			if (g[j] == 2) {
				ans++;
			}
		}
	}
	return ans;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),T = read();
	while (T--) {
		cout << solve() << "\n";
	}
	return 0;
}
