#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);                                                                                                             
	freopen("and.out","w",stdout);                                                                                                           
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	int maxn=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				maxn=max(a[i]&a[j],maxn);
			}
		}
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				for(int k=1;k<=n;k++)
				{
					if(k==i||k==j)
					{
						continue;
					}
					maxn=max(a[i]&a[j]&a[k],maxn);
				}
			}
		}
	}
	else
	{
		maxn=0;
	}
	cout<<maxn;
	return 0;
}
