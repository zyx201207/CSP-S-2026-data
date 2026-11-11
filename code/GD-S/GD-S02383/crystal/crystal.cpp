#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[500010],s[10010][10010],ans;
bool flaga=1,flagb=1;

bool checkab(ll x)
{
	if((x-1)*x*abs(a[2]-a[1])/2<=m)
	{
		return 1;
	}
	return 0;
}
void solve()
{
	deque<ll>q;
	for(ll i=1;i<=n;i++)
	{
		q.push_back(i);
		while(s[q.back()-1][q.back()]-s[q.front()-1][q.size()]>m&&!q.empty())
		{
			q.pop_front();
		}
		ll len=q.size();
		ans=max(ans,len);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			flaga=0;
		}
		if(i>2&&!(a[i]-a[i-1]==a[i-1]-a[i-2]))
		{
			flagb=0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			s[i][j]=a[j]-a[i]+s[i-1][j];
		}
	}
	if(flaga)
	{
		ll l=1,r=n;
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			if(checkab(mid))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<l;
		return 0;
	}
	else if(flagb)
	{
		ll l=1,r=n;
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			if(checkab(mid))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<l;
		return 0;
	}
	solve();
	cout<<ans;
	
	return 0;
}
