#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],maxn;
bool chk(int t,int k)
{
	return (t-k)*a[t]-(s[t-1]-s[k-1])<=m;
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i = 1;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(chk(i,mid))r=mid;
			else l=mid+1;
		}
		maxn=max(maxn,i-r+1);
	}
	cout << maxn;
	return 0;
}
