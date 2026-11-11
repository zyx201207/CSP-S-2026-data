#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e6+10;

ll a[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int op,t;
	cin>>op>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		bool f = 1;
		for(int i = 1; i<= n; i++)
		{
			cin>>a[i];
			if(i > 2 && a[i]-a[i-1] != a[i-1]-a[i-2]) f = 0;
		}
		if(!f)
		{
			cout<<0<<"\n";
			continue;
		}
		ll dis = a[n]-a[n-1];
		if(d > dis*2) cout<<0<<"\n";
		else cout<<n-3<<"\n";
	}
	return 0;
}
