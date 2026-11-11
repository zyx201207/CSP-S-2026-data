#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=n;
	while(x--)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int t=0;
		for(int i=n-x;i<=n;i++)
		{
			if(b[a[i]]==0)
			{
				b[a[i]]=++t;
				c[t]=a[i];
			}
			else
			{
				int k=b[a[i]];
				for(int j=k+1;j<=t;j++)
				{
					b[c[j]]=0;
					c[j]=0;
				}
				b[c[i]]=k;
				t=k;
			}
		}
		for(int i=1;i<=t;i++)
		{
			d[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<d[i]<<" ";
	return 0;
}
