#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
int c,t;
int a[N];
int dp[N][N];
bool vis[N][N];
void workk(){
	int n,d;
	cin>>n>>d;
	memset(a,0,sizeof a);
	memset(vis,0,sizeof vis);
	memset(dp,0,sizeof dp);
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)continue;
			if(vis[i][j-1]==1)vis[i][j]=1;
			else if(a[j]-a[j-1]>d)vis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=1;
	for(int i=1;i<=n;i++){
		int mx=lower_bound(a+1,a+1+n,a[i]+d)-a;
		if(a[mx]!=a[i]+d)mx--;
		for(int j=i;j<=mx;j++)dp[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//int mn=lower_bound(a+1,a+1+n,a[j]-d)-a;
			//int mx=lower_bound(a+1,a+1+n,a[i]+d)-a;
			//if(a[mx]!=a[i]+d)mx--;
			//cout<<mn<<' '<<mx<<'\n';
			for(int k=i+1;k<j;k++){
				dp[i][j]=dp[i][k]*dp[k][j]+dp[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		workk();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4
*/
