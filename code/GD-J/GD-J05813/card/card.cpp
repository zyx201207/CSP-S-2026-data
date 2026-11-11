#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
    int a[n+1];
    int c[n+1];
    int b[m+1];
    int d[m+1];
    for(int i=1;i<=m;i++)
    {
    	d[i]=0;
    	b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
	}
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]=0;
		}
		for(int j=1;j<=m;j++)
		{
			b[j]=0;
		}
		int y=1;
		for(int j=i;j<=n;j++)
		{
			c[y]=a[j];
			b[a[j]]++;
			if(b[a[j]]==2)
			{
				b[c[y]]--;
				c[y]=0;
				y--;
				while(c[y]!=a[j])
				{
					b[c[y]]--;
					c[y]=0;
					y--;
				}
			}
			y++;
		}
		int k=1;
		while(c[k]!=0)
		{
			d[c[k]]++;
			k++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<d[j]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
