#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[200010],ans,mn,ma[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ma[i]=a[i];
	}
	ll mn=n;

	for(int i=31;i>=1;i--)
	{
		ll tot=0;
		for(int j=1;j<=mn;j++) a[j]=ma[j];
		for(int j=1;j<=mn;j++)
		{
			if((a[j]>>(i-1)&1)==1) 
			{
				tot++;
				ma[tot]=a[j];
			}
		}
		if(tot>=m)
		{
			mn=tot;
			ans+=pow(2,i-1);
		}
		else 
		{
			tot=mn;
			for(int j=1;j<=mn;j++)
			{
				ma[j]=a[j];	
			}
		}
		
	}
	cout<<ans;
	return 0;
}
