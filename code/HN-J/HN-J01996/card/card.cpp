#include <bits/stdc++.h>
using namespace std;
int n,m,x,v[300050],a[300050];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		a[v[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}
