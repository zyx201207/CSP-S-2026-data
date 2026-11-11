#include<bits/stdc++.h>
#define int long long
const int N=500;

using namespace std;vector<pair<int,pair<int,int>>> mp[N];int w[N],a[N][N],t[N][N],dp[N][N];
void floyed(int n)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
}

signed  main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	while(q--)
	{
		int t1,t2;
		cin>>t1>>t2;
		cout<<dp[t1][t2]<<'\n';
	}
} 
