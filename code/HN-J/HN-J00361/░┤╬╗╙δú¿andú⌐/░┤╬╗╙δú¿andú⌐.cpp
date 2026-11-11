#include<bits/stdc++.h>
using namespace std;
long long  n,m;
long long a[10000][1000],b[1000000],maxn=-99999999;
int main()
{
	freopen("按位与（and）.in","r",stdin);
	freopen("按位与（and）.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		int j=0;
		while(b[i]>0)
		{
			j++;
			a[i][j]=b%2;
			b/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int ans=0;
			for(int l=1;l<=32;l++)
			{
				if(a[i][l]==1&&a[j][l]==1)
				{
					ans+=pow(2,l-1);
				}
			}
			maxn=max(maxn,ans);
		}
	}
	cout<<maxn;
	return 0;
 } 
