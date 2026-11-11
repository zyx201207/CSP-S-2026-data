#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t,n,k;scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(ll i=1,x,y;i<n;i++)scanf("%lld%lld",&x,&y); 
		printf("%lld\n",k-1);
	}
	return 0;
}
