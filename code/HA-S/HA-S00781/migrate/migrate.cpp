#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10;
int c,t,n,d,ans,a[N],dp[N][N],steps[N][N];

int main () {
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);

	scanf ("%d%d",&c,&t);
	while (t--) {
		scanf ("%d%d",&n,&d);
		for (int i=1; i<=n; i++) {
			scanf ("%d",&a[i]);
		}
		ans=0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				dp[i][j]=0;
			}
		}
		for (int k=0; k<=n; k++) {
			for (int i=k+1; i<=n; i++) {
				if (a[i]-a[i-k]<=d) {
					dp[i-k][i]=1;
					steps[i-k][i]=1;
				}
			}
		}
		for (int i=1; i<=n; i++) {
			for (int j=i+2; j<=n; j++) {
				for (int mid=i+1; mid<j; mid++) {
					if (dp[i][mid]&&dp[mid][j]) {
						if (!dp[i][j]) {
							steps[i][j]=steps[i][mid]+steps[mid][j];
							dp[i][j]=dp[i][mid]*dp[mid][j];
						} else if (steps[i][mid]+steps[mid][j]<steps[i][j]) {
							steps[i][j]=steps[i][mid]+steps[mid][j];
							dp[i][j]=dp[i][mid]*dp[mid][j];
						} else if (steps[i][mid]+steps[mid][j]==steps[i][j]) {
							dp[i][j]+=dp[i][mid]*dp[mid][j];
						}
					}
				}
			}
		}
//		for (int i=1; i<=n; i++) {
//			for (int j=1; j<=n; j++) {
//				printf ("%d ",dp[i][j]);
//			}
//			printf ("\n");
//		}
		for (int i=1; i<=n; i++) {
			for (int j=i; j<=n; j++) {
				if (dp[i][j]==2) {
					ans++;
				}
			}
		}
		printf ("%d\n",ans);
	}
	return 0;
}