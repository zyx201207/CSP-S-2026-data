#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],p[500500],cnt[500500],c = 1,ans = -1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int f=1;f<=n;f++)
	{
		for(int i=f;i<=n;i++)
		{
			p[c] = a[i];
			c++;
			for(int j=1;j<=c;j++)
			{
				if(a[i] == p[j])
				{
					for(int k=j;k<=c;k++)
					{
						p[k] = 0;
					}	
					c = j;
				}
			}
			p[c] = a[i];
			c++;
		}
		for(int i=1;i<=c;i++)
		{
			cnt[p[i]]++;	
		}
		for(int i=1;i<=c;i++)
		{
			p[i] = 0;	
		}
		c = 1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
