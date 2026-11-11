#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 1e6 + 5, MR = 3e2 + 5;
int c, t, n, m, ans, a[MAXN], lp[MAXN], rp[MAXN];
int f[MR][MR], s[MR][MR];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t --){
		n = read(), m = read(), ans = 0;
		for(int i = 1;i <= n;i ++)lp[i] = rp[i] = 0;
		for(int i = 1;i <= n;i ++)a[i] = read();
		for(int i = 1;i <= n;i ++){
			int lpos = i, rpos = n, res = i;
			while(lpos <= rpos){
				int mid = (lpos + rpos) >> 1ll;
				if((a[mid] - a[i]) <= m)res = mid, lpos = mid + 1;
				else rpos = mid - 1;
			}
			rp[i] = res;
			lpos = 1, rpos = i, res = i;
			while(lpos <= rpos){
				int mid = (lpos + rpos) >> 1ll;
				if((a[i] - a[mid]) <= m)res = mid, rpos = mid - 1;
				else lpos = mid + 1;
			}
			lp[i] = res;
		}
		if(c == 11 || c == 12){
			if(m <= (a[2] - a[1])){
				puts("0");
				continue;
			}
			int h = m / (a[2] - a[1]);
			printf("%lld\n", max(n - h * 2 + 1, 0ll));
			continue;
		}
		if(c == 13 || c == 14){
			int r = 1;
			for(int i = 1;i <= n;i ++){
				while(a[r] - a[i] <= m && r <= n)r ++;
				if(a[r] - a[i] > m)ans += (n - r + 1);
			}
			printf("%lld\n", ans);
			continue;
		}
		for(int i = 1;i <= n;i ++){
			memset(f, 0, sizeof(f));
			memset(s, 0, sizeof(s));
			f[i][0] = 1;
			for(int j = i;j <= n;j ++)s[j][0] = 1;
			for(int j = i + 1;j <= n;j ++){
				if(a[j] - a[j - 1] > m)break;
				for(int k = 1;k <= j - i;k ++){
					f[j][k] = min(s[j - 1][k - 1] - s[max(lp[j] - 1, i - 1)][k - 1], 3ll);
					s[j][k] = f[j][k] + s[j - 1][k];
				}
			}
			for(int j = i + 1;j <= n;j ++){
				if(a[j] - a[j - 1] > m)break;
				for(int k = 1;k <= j - i;k ++){
//					printf("TTT : %lld %lld %lld %lld %lld\n", i, j, k, f[j][k], s[j][k]);
					if(f[j][k]){
						if(f[j][k] == 2)ans ++;
						break;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

