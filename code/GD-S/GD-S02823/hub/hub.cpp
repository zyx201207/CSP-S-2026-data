#include<bits/stdc++.h>
using namespace std;
unsigned long long c,t,n,k,a[400000],b[400000];
int main()
{
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&k);
		for(int j=1;j<n;j++)
			scanf("%lld%lld",&a[i],&b[i]);
		if(n%2==1) cout<<k%n;
		else cout<<k%n+1;
	}
	return 0;
}
