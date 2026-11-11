#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],maxx=-1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	bool b[n+5];
	memset(b,1,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(a[j]==a[k]&&b[j])
				{
					for(int l=1;l<k;l++)
					{
						b[l]=0;
					}
					break;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(b[j])
			{
				c[a[j]]++;
			}
		}
	}
	for(int i=1;i<=maxx;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
