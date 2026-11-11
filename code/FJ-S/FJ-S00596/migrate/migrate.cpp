// Error. 0 pts
// 大样例migrate5.in里面有一个过不了 
// 不知道在干什么。彻底假掉
// O(n^3)暴力都不会写 
// 200分要退役了 
// 算了交吧，看运气（ 

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2000009;

int n, d, x[N];

int a[N], w[N], ok[N];
int f[N][2];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int C, T;
	scanf("%lld%lld", &C, &T);
	while (T--){
		scanf("%lld%lld", &n, &d);
		for (int i=1; i<=n; i++)	scanf("%lld", &x[i]);
		
//		if (n<=300){
//			int j=n;
//			for (int i=n; i; i--){
//				while (j>i && x[j]-x[i]>d)	j--;
//				a[i]=j;
//			}
//			j=1;
//			for (int i=1; i<=n; i++){
//				while (j<i && x[i]-x[j]>d)	j++;
//				b[i]=j;
//			}
//			printf("a= "); for (int i=1; i<=n; i++)	printf("%d ", a[i]); puts("");
//			printf("b= "); for (int i=1; i<=n; i++)	printf("%d ", b[i]); puts("");
//			int ans=0;
//			for (int u=1; u<=n; u++)
//				for (int v=u+1; v<=n; v++){
//					memset(vis, 0, sizeof vis);
//					int now=u;
//					while (!vis[now][0] && now!=v){
//						vis[now][0]=1;
//						now=min(a[now], v);
//					}
//					if (now!=v)	continue;
//					now=v;
//					while (!vis[now][1] && now!=u){
//						vis[now][1]=1;
//						now=max(b[now], u);
//					}
//					if (now!=u)	continue;
//					int cnt=0;
//					for (int i=u+1; i<v-1; i++)
//						if (vis[i][0]!=vis[i][1])	cnt++;
//					if (cnt==1)	ans++;
//				}
//			printf("%lld\n", ans);
//		}
//		else{
			int j=n;
			for (int i=n; i; i--){
				while (j>i && x[j]-x[i]>d)	j--;
				a[i]=j;
			}
			for (int i=1; i<=n; i++)	w[i]=a[i]-a[i-1];
			ok[1]=0;
			for (int i=2; i<=n; i++){
				if (a[i-1]!=a[i])	ok[i]=0;
				else if (a[i-2]!=a[i])	ok[i]=1;
				else	ok[i]=2;
			}
	//		if (tim==4){
	//		printf("w= "); for (int i=1; i<=n; i++)	printf("%d ", w[i]); puts("");
	//		printf("ok= "); for (int i=1; i<=n; i++)	printf("%d ", ok[i]); puts("");
	//		}
			
			int ans=0;
			for (int u=n; u; u--){
				int nxt=a[u];
				if (ok[u]==2)	/*GunMu*/;
				else if (ok[u]==1){
					f[u][1]=f[nxt][0];
				}
				else{
					f[u][0]=w[u]+f[nxt][0];
					f[u][1]=(a[u-1]!=nxt-1)? (nxt>u+1? w[nxt-1]: 0)+f[nxt][1]: f[nxt][1];
				}
				ans+=f[nxt][1]+(nxt>u+1? w[nxt-1]: 0);
	//			printf("+%d ", f[nxt][1]+(nxt>u+1? w[nxt-1]: 0));
			}
			
			printf("%lld\n", ans);
			
			for (int i=1; i<=n; i++){
				x[i]=a[i]=w[i]=ok[i]=f[i][0]=f[i][1]=0;
			}
//		}
			
	}
	return 0;
}
