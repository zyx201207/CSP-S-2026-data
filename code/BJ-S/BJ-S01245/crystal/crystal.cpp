#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=1,ans=1,l=1,r=1;
	ll ssum=0;
	while (1)
	{
		if (r>=n) break;
		if (ssum+1ll*(r-l+1)*(a[r+1]-a[r])<=m)
		{
			ssum+=1ll*(r-l+1)*(a[r+1]-a[r]);
			cnt++;
			ans=max(ans,cnt);
			r++;
		}
		else if (l==r&&ssum+(a[r+1]-a[r])>m)
		{
			l=r+1;
			r=l;
			cnt=1;
			ssum=0;
			ans=max(ans,cnt);
		}
		else if (l<r&&ssum+1ll*(r-l+1)*(a[r+1]-a[r])>m)
		{
			ssum-=(a[r]-a[l]);
			cnt--;
			ans=max(ans,cnt);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
