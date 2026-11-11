#include<iostream>
using namespace std;
int a[500005];
int b[500005];
int c[300005];
int ad1[500005],ad2[500005];
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
	int p=0;
	for(int i=1;i<=n;i++)
	{
		int now=a[i];
		if(c[now]>0)
		{
			ad1[++p]=c[now];
			ad2[p]=i-1;
		}
		c[now]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				b[j]=b[j-1]+1;
			}
		}
		int np=p;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int c=b[n];
			if(i<=ad1[p])
			{
				c-=(b[ad2[p]]-b[ad1[p-1]]);
			}
			if(c>0)
			{
				ans++;
			}
		}
		cout<<ans<<" ";
	}
}
