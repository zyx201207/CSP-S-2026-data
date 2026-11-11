#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,l;
long long s[500005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&d);
		for(int j=1;j<=n;j++)
		scanf("%lld",&s[i]);long long k=0,l=0;
		while(d<=k)d+=s[2]-s[1],l++;
		cout<<n/2<<'\n';
	}
	
	
}

