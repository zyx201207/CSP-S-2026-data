#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005][40],t,ans,tong[200005],sum[200005],now;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=1;j<=32;j++)
		{
			if(t%2==1)
			{
				sum[j]++;
			}
			a[i][j]=t%2;
			t/=2;
			if(t==0)
			{
				break;
			}
		}
	}
	now=n;
	for(int i=32;i>=1;i--)
	{
		if(sum[i]>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)
				{
					tong[j]++;
					if(tong[j]==1)
					{
						now--;
					}
				}
			}
			if(now<m)
			{
				break;
			}
			ans+=(1<<(i-1));
		}
	}
	cout<<ans;
	return 0;
}
