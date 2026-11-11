#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,a[200010],mid,hr,la,ans;
ll s,sa[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);	
		cin>>c[i];
		s+=a[i];
		sa[i]=s-a[i]+1;
	}
	mid=s/2;	
	hr=s,la=n;
	for(int i=1;i<=n;i++)
	{
		if(sa[i]>mid) break;
		ll qlen=min(mid,sa[i]+a[i]-1)-(sa[i]-1),hl=hr-qlen+1;
		while(sa[la]>=hl)
		{
			
			if(c[la]!=c[i]) ans+=min(hr-sa[la]+1,a[la]);
			hr=sa[la]-1;
			la--;
		}
		if(hr>=hl)
		{
			if(c[la]!=c[i]) ans+=(hr-hl+1);
			hr=hl-1;
		}	
	}
	cout<<ans;
	return 0;
}
