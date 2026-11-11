#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
constexpr int MAXN=2e5+10;

int n;
pair<int,char> a[MAXN];
int sum;
int ans;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].fi>>a[i].se;
		sum+=a[i].fi;
	}
	int j=n;
	for(int i=1;i<=n;)
	{
		if(i==j) break;
		if(a[i].fi==0) ++i;
		if(a[j].fi==0) --j;
		if(a[i].se!=a[j].se)
		{
			int now=min(a[i].fi,a[j].fi);
			ans+=now;
			a[i].fi-=now;
			a[j].fi-=now;
		}
		else
		{
			int now=min(a[i].fi,a[j].fi);
			a[i].fi-=now;
			a[j].fi-=now;
		}
	}
	cout<<ans;
	return 0;
}