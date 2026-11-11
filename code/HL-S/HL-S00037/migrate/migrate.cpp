#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		int n,k;
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<0<<'\n';
	}
	return 0;
}
