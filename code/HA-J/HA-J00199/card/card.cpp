#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[200005],c,d,e[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c=0;
		d=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=j-1;k++)
			{
				if(a[j]==a[k])
				{
					c=j;
					d=k;
					break;
				}
			}
			for(int g=d;g<c;g++)
		    {
		        e[g]=1;
		    }
	    }
		for(int j=i;j<=n;j++)
		{
			if(e[j]==0)
			{
				b[a[j]]++;
			}
		}
    }
    for(int i=1;i<=m;i++)
    {
    	cout<<b[i]<<" ";
    }
}
