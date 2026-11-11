#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int INF=0x3f3f3f3f;
const int N=5e5+10;
ll n,m;
ll a[N],ans;
ll check(ll l,ll r)
{
	ll s=0;
	for(int i=l;i<r;i++)
	{
		s+=a[r]-a[i];
	}
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(1,mid)>m) r=mid-1;
		else 
		{
			ans=max(ans,mid);
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
