#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	ll ans=0LL;
	while (l<r)
	{
		ll minn=min(a[l],a[r]);
		if (c[l]==c[r])
		{
			a[l]-=minn;
			a[r]-=minn;
			if (a[l]==0)
			{
				l++;
			}
			if (a[r]==0)
			{
				r--;
			}
		}
		else
		{
			ans+=minn;
			a[l]-=minn;
			a[r]-=minn;
			if (a[l]==0)
			{
				l++;
			}
			if (a[r]==0)
			{
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

