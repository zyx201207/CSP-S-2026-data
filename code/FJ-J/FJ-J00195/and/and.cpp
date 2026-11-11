#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000000009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxx=0;
	for(int i=1;i<=n-m+1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			maxx=max(a[i]&a[j],maxx);
		}
	}
	cout<<maxx;
	return 0;
}
