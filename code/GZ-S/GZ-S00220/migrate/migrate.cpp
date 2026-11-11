/*
	准考证号：GZ-S00220
	学校：华麟学校
	姓名：刘凌睿
*/
#include<bits/stdc++.h>
using namespace std;
int a[2000005],dp[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
			}
		}
	}
	return 0;
}
