#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+114;
const int inf=0x3f3f3f3f;
ll a[N],ans,m,sum[N],k[N];
bool flag;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k[i]=a[i]-i*a[i];
		if(i>=3 and a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			flag=1;
		}
	}
	sort(a+1,a+n+1);
	if(!flag)
	{
		int k=log2(n);//k~k+1
		ll cnt=0,b=n/2,num=-1,h=a[2]-a[1];
		for(int i=1;i<=k+1;i++)
		{
			ll c=(ll)pow(2,i-1);
			if(cnt+c*b*h>m)
			{
				num=i-1;
				break;
			} 
			cnt+=c*b*h;
		}
		(num==-1) ? ans=n : ans=pow(2,num);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i]+sum[i-1];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			ll cnt=(j-i+1)*a[j]-(sum[j]-sum[i-1]);
			if(cnt<=m)
			{
				ans=max(ans,j-i+1);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
5 5
1 2 4 8 9

*/
