#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d,a[N],ans,dp[1005][1005],dp1[1005][1005],cnt,b[1005][1005];
void dfs(int x,int y,int cnt){
	if (cnt>dp1[y][x]) return ;
	dp[y][x]++;
	for (int i=x+1;i<=n;i++){
		if (a[i]-a[x]<=d){
			dfs(i,y,cnt+1);
		}
	}
}
void dfs1(int x,int y,int cnt){
	dp1[y][x]=min(dp1[y][x],cnt);
	for (int i=x+1;i<=n;i++){
		if (a[i]-a[x]<=d){
			dfs1(i,y,cnt+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (n<=9){
			ans=0;
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					dp[i][j]=0;
					dp1[i][j]=1e18;
				}
			}
			for (int i=1;i<=n;i++){
				dfs1(i,i,0);
			}
			for (int i=1;i<=n;i++){
				dfs(i,i,0);
			}
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (dp[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		else if (n<=300){
			ans=0;
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					dp[i][j]=0;
					dp1[i][j]=1e18;
				}
			}
			for (int i=1;i<=n;i++){
				dp1[i][i]=0;
			}
			for (int k=1;k<=n;k++){
				for (int i=k;i<=n;i++){
					for (int j=i+1;j<=n;j++){
						if (a[j]-a[i]<=d){
							dp1[k][j]=min(dp1[k][j],dp1[k][i]+1);
						}
					}
				}
			}
			for (int k=1;k<=n;k++){
				for (int i=k;i<=n;i++){
					for (int j=i+1;j<=n;j++){
						if (a[j]-a[i]<=d&&dp1[k][j]==b[k][i]+1){
							dp[k][j]++;
							b[k][j]++;
						}
					}
				}
			}
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (dp[i][j]==2) ans++;
				} 
			}
			cout<<ans<<"\n";
		} 
	}
	return 0;
}
