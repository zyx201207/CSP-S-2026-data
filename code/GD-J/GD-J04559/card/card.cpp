#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500010],jg[500010];
bool a1[500010],a2[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (long long z=1;z<=n;z++)
	{
		for (long long i=1;i<=n;i++)
		{
			a1[i]=true;
			a2[i]=false;
		}
		for (long long i=z;i<=n;i++)
		{
			if (a1[i]==false)
			{
				continue;
			}
			for (long long j=i+1;j<=n;j++)
			{
				if (a[i]==a[j])
				{
					if (a1[j]==false)
					{
						continue;
					}
					for (long long x=i+1;x<=j;x++)
					{
						a1[x]=false;
					}
				}
			}
		}
		for (long long i=z;i<=n;i++)
		{
			if (a1[i]==true)
			{
				a2[a[i]]=true;
			}			
		}
		for (long long i=1;i<=n;i++)
		{
			if (a2[i]==true)
			{
				jg[i]++;
			}
		}
	}
	for (long long i=1;i<=m;i++)
	{
		cout<<jg[i]<<' ';
	}
	return 0;
}
