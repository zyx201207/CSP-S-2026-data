#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,d,a[N];
int main()
{
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while (T--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if (a[2]-a[1]==d/2)
		{
			cout<<n-3<<"\n";
		}
		else
		{
			cout<<0<<"\n";
		}
	}
	return 0;
}
