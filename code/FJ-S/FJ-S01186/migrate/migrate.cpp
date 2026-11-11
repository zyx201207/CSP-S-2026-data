#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,M=2e6+5;
int a[M];
int dp[N][N],dp1[N][N],flag[N][N],dpp[M],flagg[M],dpp1[M];
int as[M];
int c,_;
inline void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int ans=0;
	for(int i=1;i<=n+1;i++)dpp[i]=dpp1[i]=1e18,flagg[i]=0,as[i]=0;
	if(c==11||c==12){
		dpp[1]=0;
		int cnt=1;
		for(int j=2;j<=n;j++){
			if(a[j]>a[j-1]+m)break;
			while(a[cnt]+m<a[j])cnt++; 
			dpp[j]=dpp[cnt]+1;
			dpp1[j]=min(dpp[cnt+1]+1,dpp1[cnt]+1);
			if(dpp1[j]==dpp[cnt+1]+1)flagg[j]+=1;
			if(dpp1[j]==dpp1[cnt]+1)flagg[j]+=flagg[cnt]; 
			if(dpp1[j]==dpp[cnt+2]+1)flagg[j]+=1;
			if(dpp1[j]==dpp1[cnt+1]+1)flagg[j]+=flagg[cnt+1];
			if(dpp1[j]==dpp[j]&&flagg[j]==1){
				ans++;
			}
			as[j]=ans;
		}
		int sum=0;
		for(int j=2;j<=n;j++)sum+=as[j];
		cout<<sum<<'\n';
		return ; 
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++)dp[i][j]=dp1[i][j]=1e18,flag[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		int cnt=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[j-1]+m)break;
			while(a[cnt]+m<a[j])cnt++; 
			dp[i][j]=dp[i][cnt]+1;
			dp1[i][j]=min(dp[i][cnt+1]+1,dp1[i][cnt]+1);
			if(dp1[i][j]==dp[i][cnt+1]+1)flag[i][j]+=1;
			if(dp1[i][j]==dp1[i][cnt]+1)flag[i][j]+=flag[i][cnt]; 
			if(dp1[i][j]==dp[i][cnt+2]+1)flag[i][j]+=1;
			if(dp1[i][j]==dp1[i][cnt+1]+1)flag[i][j]+=flag[i][cnt+1];
			if(dp1[i][j]==dp[i][j]&&flag[i][j]==1){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>_;
	while(_--){
		solve();
	} 
 } 
 /*
0 1
9 3
1 3 5 7 8 10 12 13 14
 */
