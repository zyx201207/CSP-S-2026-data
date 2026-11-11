#include <bits/stdc++.h>
using namespace std;
int a[500001],tab[300001],ans[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,c=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int f=0,pos;
			for(int k=1;j<i;k++)
				if(a[k]==a[j])
				{
					f=1;
					pos=k;
				}
			if(f==1)
			{
				for(int k=pos;k<=c;k++)tab[k]=0;
				c=pos;
				tab[c]=a[j];
			}
			else
			{
				tab[c]=a[j];
				c++;
			}
		}
		for(int j=1;j<=m;i++)ans[tab[j]]++;
		c=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
