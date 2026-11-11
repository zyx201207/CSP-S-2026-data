#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10007;//2e6+7;
ll C, T, n, d, a[N], f[N], g[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &C, &T);
	while(T--) {
		scanf("%lld%lld", &n, &d);ll ans=0;
		for(int i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		for(int i=1; i<=n; i++) {
			fill(f, f+n+1, N);
			fill(g, g+n+1, 0), f[i]=0, g[i]=1;
			for(int j=i; j<=n; j++)
				for(int k=j+1; a[k]-a[j]<=d && k<=n; k++)
					if(f[j]+1<f[k]) f[k]=f[j]+1, g[k]=g[j];
					else if(f[j]+1==f[k])  g[k]+=g[j];
			for(int j=1; j<=n; j++) if(g[j]==2) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
