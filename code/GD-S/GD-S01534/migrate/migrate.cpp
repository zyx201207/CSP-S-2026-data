#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof x);
		int n,d,mx=0;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=2;i<=n;i++)mx=max(mx,x[i]-x[i-1]);
		if(mx<=d)cout<<n-3<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
