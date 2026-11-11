#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0)
ll c,t,n,d,a[2000006],ans[2000006],cnt[2000006];
ll find(ll l,ll r,ll x)
{
	ll res=-1;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (a[mid]+d>=x)
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return res;
}
int main()
{
	faster;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		ll res=0;
		for (ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if (c==13||c==14)
		{
			for (ll i=3;i<=n;i++)
			{
				ll x=find(1,i-1,a[i]);
				if (x+2>i)continue;
				res+=find(1,x+1,a[x+2])-find(1,x,a[x+1]);
			}
			cout<<res<<"\n";
			continue;
		}
		for (ll i=1;i<=n;i++)
		{
			ans[i]=0;
			cnt[i]=0;
			for (ll j=i+1;j<=n;j++)
			{
				ll x=find(i,j-1,a[j]);
				if (x==-1)break;
				ans[j]=ans[x]+1;
				if (x+2<=j&&ans[x]==ans[x+2])cnt[j]=2;
				else if (ans[x]==ans[x+1])
				{
					cnt[j]=max(cnt[x],cnt[x+1])+1;
				}
				else
				{
					cnt[j]=cnt[x];
				}
				if (cnt[j]==1)res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}