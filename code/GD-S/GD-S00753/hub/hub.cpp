#include<bits/stdc++.h>
using namespace std;
long long c,q,n,m,l,r,mi;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>q;
	while(q--)
	{
		cin>>n>>m;
		mi=1e18+7;
		for(int i=1;i<n;i++) scanf("%lld%lld",&l,&r),mi=min(mi,abs(r-l));
		printf("%lld\n",mi);
	}
	return 0;
}
