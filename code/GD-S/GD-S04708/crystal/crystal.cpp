#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum[N],ans=1;
ll d[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i];
	}
	ll s=0,cur=0;
	for(ll i=2,j=1;i<=n;i++)
	{
		cur=(i-j)*d[i];
		while(j<i&&s>(m-cur))
		{
			s-=(sum[i]-sum[j]);
			j++;
		}
		s+=cur;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
