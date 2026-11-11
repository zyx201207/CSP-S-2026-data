#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
bool c[10005];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//  ios::sync_with_stdio(false);
//  cin.tie(0);
	int n,m,x=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(x<=n)
	{
		int z;
		for(int i=x;i<=n;i++)
		{
			z=a[i];
			c[z]=1;
		}
		
		for(int i=1;i<=m;i++)
		{
			if(c[i]==1)
			{
				b[i]++;
				c[i]=0;
			}
		}
		x++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
