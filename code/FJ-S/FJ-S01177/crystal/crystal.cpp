#include<bits/stdc++.h>
#define mid (l+r>>1)
#define ll long long
#define N 500010
using namespace std;
int n,ans=1;
ll k;
ll a[N],s[N];
bool check(ll x,ll y)
{
	return (y-x)*a[y]-(s[y-1]-s[x-1])<=k;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			if(check(mid,i))
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
