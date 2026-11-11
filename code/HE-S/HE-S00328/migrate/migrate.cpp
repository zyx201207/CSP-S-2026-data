#include<bits/stdc++.h>
using namespace std;
long long c,t;
signed main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) 
	{
		long long n,d;
		cin>>n>>d;
		long long p=n;
		while(n--) cin>>d;
		if(p%2==0) cout<<"0\n";
		else cout<<p<<"\n";
	}
	return 0;
}

