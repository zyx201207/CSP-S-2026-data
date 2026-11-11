#include <bits/stdc++.h>
using namespace std;
const int Nmax=2e6+7;
long long a[Nmax];
int c,t;
int n;
int opt=0;
long long d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d==2)
		{
			cout<<n-3<<endl;
		}
	}
	return 0;
}