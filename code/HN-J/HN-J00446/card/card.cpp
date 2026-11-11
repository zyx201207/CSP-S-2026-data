#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			b[1]=max(b[1],i);
		}
	}
	for(int i=2;i<=m;i++)
	{
		b[i]=b[i-1]+1;
		for(int j=b[i-1]+1;j<=n;j++)
		{
			if(a[j]==i)
			{
				b[i]=max(b[i],j);
			}
			else
			{
				break;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
