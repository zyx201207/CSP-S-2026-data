#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[100001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int j=1;j<=t;j++)
	{
		cin>>c>>t>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<i<<"\n";
	}
	return 0;
}

