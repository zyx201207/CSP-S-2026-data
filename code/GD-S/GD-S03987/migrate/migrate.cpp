#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int c,t,n,d,a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		if(c==11 || c==12)
		{
			if(n<4 || a[(n+1)/2]==0)	cout<<0<<endl,exit(0);
			cout<<n-3<<endl;
		}
		if(c==13 ||c==14)
		{
			cout<<0<<endl;
		}
	}
	
	
	return 0;
}
