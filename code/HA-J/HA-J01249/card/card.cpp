#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int b[m+1]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[x];
		for(int j=1;i<i;i++)
		{
			if(a[j]==a[i])
			{
				for(int y=j+1;y<=i;y++)
				{
					a[y]=0;
					x--;
				}
			}
		}
		x++;
		for(int j=1;j<=n;j++)
		{
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
