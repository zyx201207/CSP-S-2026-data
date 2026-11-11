#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long  a[200002], n, m, maxx=-999;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=m; j++)
	    {
		    if((a[j]&a[j+1])>maxx)
		    {
		    	maxx=(a[j]&a[j+1]);
			}
	    }
	}
	cout<<maxx;
	return 0;
}
