#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000010];
long long f[2010][2010];
long long d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(d<x[4]-x[2] || d>=x[4]-x[1])
		{
			cout<<0<<'\n';
			continue;
		}
		cout<<n-3<<'\n';
	}
	return 0;
}
