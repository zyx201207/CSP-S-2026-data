#include <bits/stdc++.h>
using namespace std; typedef long long ll;
const int N = 2000005;
int c,t,n,dis[N],f[N],l[N]; ll x[N],d;
ll read() {
	ll w = 0,f = 1; char c = getchar();
	while (!isdigit(c) && c!='-') c = getchar();
	if (c == '-') f = -1,c = getchar();
	while (isdigit(c)) w = w*10+(c-'0'),c = getchar();
	return w*f;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	while (t--) {
		n = read(),d = read(); ll ans = 0;
		for (int i = 1;i <= n;i++) {
			x[i] = read();
			l[i] = lower_bound(x+1,x+i+1,x[i]-d)-x;
		}
		for (int s = 1;s <= n;s++) {
			for (int i = s;i <= n+2;i++)
				dis[i] = 1e9,f[i] = 0;
			dis[s] = 0,f[s] = 1;
			for (int i = s+1;i <= n;i++) {
				int L = max(l[i],s);
				dis[i] = i==L?1e9:dis[L]+1,f[i] = f[L];
				if (dis[L+1] == dis[L]) f[i] += f[L+1];
				if (dis[L+2] == dis[L]) f[i] += f[L+2];
				f[i] = min(f[i],3),ans += f[i]==2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
