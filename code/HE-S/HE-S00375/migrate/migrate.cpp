#include<cstring>
#include<iostream>
#define int long long
const int N = 5000 + 5;
int f[N],cnt[N],n,T,c,x[2000005],d,ans;
void in(int & n) {
	int res = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')
		res = res * 10 + ch - '0',ch = getchar();
	n = res * f;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	in(c),in(T);
	while(T --) {
		in(n),in(d),ans = 0;
		for(int i = 1; i <= n; i ++) in(x[i]);
		if(c <= 10) {
			for(int i = 1; i <= n; i ++) {
				memset(f,0x3f,sizeof f);
				memset(cnt,0,sizeof cnt);
				cnt[i] = 1,f[i] = 0;
				int k = i,l = i;
				for(int j = i + 1; j <= n; j ++) {
					while(x[j] - x[k] > d) k ++;
					l = std::max(l,k);
					while(f[l + 1] == f[k]) l ++;
					f[j] = f[k] + 1,cnt[j] = cnt[l] - cnt[k - 1];
					if(cnt[j] == 2) ans ++;
					cnt[j] += cnt[j - 1];
				}
			}
			printf("%lld\n",ans);
		} else if(c == 11 || c == 12) {
			memset(f,0x3f,sizeof f);
			memset(cnt,0,sizeof cnt);
			cnt[1] = 1,f[1] = 0;
			int k = 1,l = 1;
			for(int i = 2; i <= n; i ++) {
				while(x[i] - x[k] > d) k ++;
				l = std::max(l,k);
				while(f[l + 1] == f[k]) l ++;
				f[i] = f[k] + 1,cnt[i] = cnt[l] - cnt[k - 1];
				if(cnt[i] == 2) ans += n - i + 1;
				cnt[i] += cnt[i - 1];
			}
			printf("%lld\n",ans);
		} else if(c == 13 || c == 14) {
			x[0] = - 5e18,x[n + 1] = 5e18;
			int cntl = 0,cntr = 0,pos = 0;
			for(int i = 1; i <= n; i ++)
				if(x[1] + d >= x[i] && x[n] - d <= x[i])
					pos = i;
			for(int i = 1; i <= pos - 2; i ++)
				cntl += ((x[i] + d) < x[pos + 1]);
			for(int i = pos + 1; i <= n; i ++)
				cntr += ((x[pos - 1] + d) >= x[i] && (x[pos - 2] + d) < x[i]);
			ans += cntl * cntr;
			cntl = 0,cntr = 0;
			for(int i = 1; i <= pos - 1; i ++)
				cntl += (x[i] + d >= x[pos + 1] && x[i] + d < x[pos + 2]);
			for(int i = pos + 2; i <= n; i ++)
				cntr += (x[pos - 1] + d < x[i]);
			ans += cntl * cntr;
			printf("%lld\n",ans);
		}
	}
}
