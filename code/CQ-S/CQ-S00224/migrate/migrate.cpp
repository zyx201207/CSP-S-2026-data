#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[2000010];
int dp[5010][5010];
int da[5010][5010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	while(t--)
	{
		memset(a,sizeof(a),0);
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				da[i][j]=2e19;
			}
		}
		for(int i=1;i<=n;i++) da[i][i]=i-1;
		for(int i=2;i<=n;i++)
		{
			for(int l=1;l<=n;l++)
			{
				int r=l+i-1;
				if(abs(a[l]-a[r])<=d) 
				{
					int la=r-1;
					if(la<da[l][l])
					{
						dp[l][r]=1;
						da[l][r]=la;
					}
					else if(la==da[l][r])dp[l][r]+=1;
				}
				else 
				{
					for(int j=l+1;j<r;j++)
					{
						if(abs(a[l]-a[j])<=d&&abs(a[r]-a[j])<=d)
						{
							int la=da[l][j]+da[j][r];
							if(la<da[l][r])
							{
								dp[l][r]=1;
								da[l][r]=la;
							}
							else if(la==da[l][r])dp[l][r]+=1;
						}
					}
				}
				
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				if(dp[i][j]==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
254
8
5
6
7
6
0
0
1
2
0
2
4
6
2
7
0
*/
