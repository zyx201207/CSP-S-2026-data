#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll n,m,a[maxn],s[maxn];
bool check(ll x)
{
	ll sum=0,cnt=0,mn=maxn;
	for(int i=x;i<=n;i++)
	{
		for(int j=i;j>=i-x+2;j--)
		{
			sum+=s[j]+cnt;
			cnt+=s[j];
		}
		mn=min(mn,sum);
	}
	return mn<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
} 
