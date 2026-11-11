#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d;
int isl[N];
//int dp[N][N];
//int val[N][N];
int dis;
//void k()
//{
//	for(int k=1;k<=n;k++)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
//			}
//		}
//	}
//}

int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>isl[i];
		}
		dis=isl[2]-isl[1];
		if(dis>d)
		{
			cout<<"0"<<'\n';
			continue;
		}
		int t=d/dis;
		
		int tag=2*t-1;
		if(n>tag)cout<<n-tag;
		else cout<<0;
	}
	return 0;
 } 

