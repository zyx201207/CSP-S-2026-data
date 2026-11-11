#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,a[N],b[N],cnt,ans,cnt1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			cnt++;
		}
		if(a[i]-a[i-1]==a[2]-a[1] && i!=1)
		{
			cnt1++;
		}
	}
	sort(a+1,a+1+n);
	b[1]=0;
	for(ll i=2; i<=n; i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1]);
	}
	if(cnt1==n-1)
	{
		for(ll i=n; i>=1; i--)
		{
			if(a[n]-a[i]<=m)
			{
				m=m-(a[n]-a[i]);
				ans++;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(cnt==n)
	{
		for(ll i=n; i>=1; i--)
		{
			if(a[n]-a[i]<=m)
			{
				m=m-(a[n]-a[i]);
				ans++;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1; i<=n; i++)
	{
		for(ll j=i; j<=n; j++)
		{
			if(b[j]-b[i-1]<=m)
			{
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
