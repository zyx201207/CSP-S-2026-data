#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f;
int c,t;
int n,d;
int a[200005],dp[5005][5005];
int ans[5005][5005];
int res;
signed main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			//cout<<a[i]<<' ';
			for(int j=1;j<=n;j++) {
				dp[i][j]=INF;
				ans[i][j]=0;
			}
		}
		//cout<<endl;
		res=0;
		for(int i=1;i<=n;i++) {
			dp[i][i]=0;
			ans[i][i]=1;
			int last=i;
			for(int j=i+1;j<=n;j++) {
				if(a[j]-a[j-1]>d) {
					break;
				}
				for(int v=j-1;v>=last;v--) {
					if(a[j]-a[v]>d) {
						last=v+1;
						break;
					}
					//cout<<i<<" "<<j<<" "<<v<<" "<<endl;
					if(dp[i][j]==INF) {
						dp[i][j]=dp[i][v]+1;
						//cout<<i<<" "<<v<<endl;
						ans[i][j]=ans[i][v];
					}
					else {
						if(dp[i][j]>dp[i][v]+1) {
							//cout<<i<<" "<<v<<" "<<j<<endl;
							dp[i][j]=dp[i][v]+1;
							ans[i][j]=ans[i][v];
							//last=v;
						}
						else {
							if(dp[i][j]==dp[i][v]+1) {
								ans[i][j]+=ans[i][v];
							}
						}
					}
				}
			}
			for(int j=i;j<=n;j++) {
				if(ans[i][j]==2) {
					res++;
					//cout<<i<<" "<<j<<endl;
				}
				//cout<<dp[i][j]<<' ';
			}
			//cout<<endl;
		}
		cout<<res<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
8 3
0 1 2 4 8 10 11 13

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
