#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int t=1;t<=n;t++)
	{
		bool c[300005],d[300005];
		int p[300005];
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(c));
		memset(p,0,sizeof(c));
		for(int i=t;i<=n;i++)
		{
			if(c[a[i]])
			{
				for(int x=p[a[i]];x<i;x++)
				{
					d[a[x]]=1;
				}
				b[a[i]]++;
			}
			else
			{
				c[a[i]]=1;
				p[a[i]]=i;
			}
		}
		for(int i=t;i<=n;i++)
		{
			if(!d[a[i]])
			{
				b[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
