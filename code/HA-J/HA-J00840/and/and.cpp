#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-2,sum;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=m+i;j++)
		{
			if(a[j]|a[j]>maxx)
			{
				maxx=a[i]|a[j];
			}
		}
	}
	cout<<maxx;
	return 0;
}
