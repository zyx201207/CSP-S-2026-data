#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[500015],ans=1,cnt[500015],s[500015];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(ll i=2;i<=n;i++)
	{
		if(a[i-1]+m<a[i]) {
			cnt[i]=1;
			continue;
		}
		else if(a[i]==a[i-1])
		{
			cnt[i]=cnt[i-1]+1;
		}else
		{
			ll sum=m,k=1;
			ll l=1,r=i,mid;
			while(l<=r)
			{
				mid=l+r>>1;
				if(s[i]-s[mid-1]+m>=(i-mid+1)*a[i])
				{
				    r=mid-1;
				}else l=mid+1;
			}
		    
		    cnt[i]=i-r;
		}
		
		
		ans=max(ans,cnt[i]);
	}
	cout<<ans;
	return 0;
}
