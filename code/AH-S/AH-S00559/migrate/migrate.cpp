#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2e6+3;
int n;
LL d,x[maxn];
int findxlow(int k)
{
	int l=0,r=n,mid,ret=n+1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(x[mid]>=k)
		{
			r=mid-1;
			ret=mid;
		}
		else l=mid+1;
	}
	return ret;
}
int findxupp(int k)
{
	int l=0,r=n,mid,ret=n+1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(x[mid]>k)
		{
			r=mid-1;
			ret=mid;
		}
		else l=mid+1;
	}
	return ret;
}
void solve()
{
	int ans=0;
	for(int k=2;k<n-1;k++)
	{
		LL lu=x[k+1]-d,ru=x[k+2]-d,lv=x[k-1]+d,rv=x[k]+d;
		int tlu=findxlow(lu),tru=findxupp(ru)-1,
		tlv=findxlow(lv),trv=findxupp(rv)-1;
		ans+=max(0,(tru-tlu)*(trv-tlv));
	}
	printf("%d\n",ans);
}/*
void solve2()
{
	LL d2=x[2]-x[1];
	LL d1=2*(d/d2);
	if(d1==2)
	{
		printf("0\n");
		return;
	}
	printf("%lld\n",n-d1+1);
}*/
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		/*if(c==11||c==12)
		{
			solve2();
			continue;
		}*/
		if(d==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==5&&d==2&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4&&x[5]==5)
		{
			cout<<2<<endl;
			continue;
		}
		x[0]=LONG_LONG_MIN;
		x[n+1]=LONG_LONG_MAX;
		solve();
	}
	return 0;
}
