#include <bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[500010];
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
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			c[a[j]]++;
			for(int k=i;k<=j-1;k++)
			{
				if(a[k]==a[j])
				{
					j=k;
					break;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(c[j]>0)
			{
				c[j]=0;
				b[j]++;
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
}
