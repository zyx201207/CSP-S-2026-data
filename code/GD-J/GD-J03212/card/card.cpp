#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[105][105],c[1000005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			c[i]+=b[i][1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i];
	}
} 
