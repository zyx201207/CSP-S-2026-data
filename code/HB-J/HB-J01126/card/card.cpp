#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5010],b[5010];
int main()
{
//	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int c[50010]={0};
		int x=1;
		c[x]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				c[50010]={0};
				x=1;
				c[x]=a[j];
			}
			else
			{
				x++;
				c[x]=a[j];
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int z=1;z<=m;z++)
			{
				if(c[k]==z&&b[z]==0)
					b[z]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
