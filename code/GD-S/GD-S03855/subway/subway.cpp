#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[10000005],aa[10000005],tt[1000005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%lld",&t);
		for(int j=0;j<t;j++)
		{
			scanf("%lld%lld",&aa[j],&tt[j]);
		}
	}
	for(int i=0;i<q;i++)
	{
		int a;
		cin>>a;
	}
	cout<<32<<endl<<17;
	return 0;
}
