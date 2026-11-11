#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
int n,m,c,a[50010];
bool f[50010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal,out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]+a[j]==a[j+1]||a[j]==a[j+1])
			{
				a[j]=a[j]*2;
				if(f[j]!=0)
				{
					c++;
				}
				f[j]=0;
			}
			else
			{
				break;
			}
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		cin>>ai;
		for(int j=ai;j<=m;j++)
		{
			dp[j]=max(dp[j],dp[j-ai]+ai);
		}
	}
	cout<<dp[m];
	*/
	cout<<c;
	return 0;
}
