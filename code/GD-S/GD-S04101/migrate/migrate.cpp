#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, s, a[2000005], f[2000005], g[2000005];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &d);
		for(int i=1; i<=n; i++){
			scanf("%lld", &a[i]);
		}
		if(n>5000){
			int h=d/(a[2]-a[1]);
			if(h+h-1>n||h<=1) puts("0");
			else printf("%lld\n", n-h-h+1);
			continue;
		}
		s=0;
		for(int i=1; i<n; i++){
			for(int i=1; i<=n; i++){
				f[i]=0, g[i]=1e18;
			}
			f[i]=1, g[i]=0;
			for(int j=i+1; j<=n; j++){
				int x=lower_bound(a+i, a+j, a[j]-d)-a;
				for(int k=x; k<j, g[k]==g[x]; k++) f[j]+=f[k];
				g[j]=g[x]+1;
				if(f[j]==2) s++;
			}
		}
		printf("%lld\n", s);
	}
	return 0;
}
