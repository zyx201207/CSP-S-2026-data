#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n;unsigned long long d;cin>>n;cin>>d;long long a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(n==1||n==2||n==3||d==1) {cout<<0<<'\n';continue;}
		else if(n==d+1) {cout<<0<<'\n';continue;}
		else if(d==2)
		{
			if(n%d==1) {cout<<2<<'\n';continue;}
			else {cout<<1<<'\n';continue;}
		}
		else if(d==3)
		{
			if(n==4) cout<<0<<'\n';
			else if(n==5) cout<<0<<'\n';
			else if(n==6) cout<<0<<'\n';
		}
		else
		{
			if(n%d==d-1) cout<<d<<'\n';
			else cout<<0<<'\n';
		}
	}
	
	
	return 0;
}
