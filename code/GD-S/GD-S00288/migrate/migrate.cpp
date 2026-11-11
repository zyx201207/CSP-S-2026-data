#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e6+114;
const int inf=0x3f3f3f3f;
ll n,c,q,d;
ll a[N],flag;
ll ans;
ll get(int x,int y)
{
	if(x==y)return 0LL; 
	ll dis=abs(a[x]-a[y])/d;
	if(abs(a[x]-a[y])%d!=0)dis++;
	return dis;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&q);
	while(q--)
	{
		scanf("%lld%lld",&n,&d);
		flag=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(d<a[2]-a[1])
		{
			printf("0\n");
		}
		else
		{
			ll k=d/(a[2]-a[1]);
			for(int i=1;i<=n;i++)
			{
				ans+=max(0LL,(n-i)/k-1);
			}
			 printf("%lld\n",ans);
		}
		
	}
	return 0;
}
/*
10 21
0 7 14 21   28 35 42 49   56 63
*/ 

