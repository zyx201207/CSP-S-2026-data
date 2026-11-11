#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN=2e5+5;
int a[MAXN],dp[MAXN],n,m;
bool vis[MAXN];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	dp[0]=-1;
	for(int i=1;i<=m;i++) {
		int p=1,mx=dp[i-1]&a[1];
		for(int j=1;j<=n;j++) {
			if(vis[j]) continue;
			if(dp[i-1]&a[j]>=mx) {
				mx=dp[i-1]&a[j];
				p=j;
			}
		}
		vis[p]=1;
		dp[i]=mx;
	}
	printf("%d",dp[m]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
