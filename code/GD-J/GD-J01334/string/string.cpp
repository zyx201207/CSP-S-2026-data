#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200010];char s[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld %c",&a[i],&s[i]);
	ll l=1,r=n,ans=0,lstl=0,lstr=0;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			if(a[l]-lstl>a[r]-lstr)
			{
				lstl+=a[r]-lstr;r--,lstr=0;
			}
			else if(a[l]-lstl<a[r]-lstr)
			{
				lstr+=a[l]-lstl;l++,lstl=0;
			}
			else l++,r--,lstl=0,lstr=0;
		}
		else
		{
			if(a[l]-lstl>a[r]-lstr)
			{
				ans+=a[r]-lstr;
				lstl+=a[r]-lstr;r--,lstr=0;
			}
			else if(a[l]-lstl<a[r]-lstr)
			{
				ans+=a[l]-lstl;
				lstr+=a[l]-lstl;l++,lstl=0;
			}
			else ans+=a[l]-lstl,l++,r--,lstl=0,lstr=0;
		}
	}
	printf("%lld",ans);
	return 0;
}
