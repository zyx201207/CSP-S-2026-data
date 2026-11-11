#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if (d<=(a[2]-a[1]))
		{
			cout<<0<<'\n';
			continue;
		}
		long long w=d/(a[2]-a[1]);
		if (w==n)
		{
			cout<<0<<'\n';
			continue;
		}
		w*=2;
		w--;
		cout<<n-w<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
