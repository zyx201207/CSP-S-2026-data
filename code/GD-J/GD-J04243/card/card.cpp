#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l=0,b[300005],c[300005],h=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		h=1;
		for(int i=1;i<=m;i++)b[i]=0;
		for(int j=i;j<=n;j++)
		{
			b[h]=a[j];
			h++;
			for(int k=1;k<h;k++)
			{
				if(b[k]==b[h-1]&&k!=h-1)
				{
					for(int ii=k+1;ii<=h-1;ii++)
					{
						b[ii]=0;
						h--;
					}
					break;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
}
