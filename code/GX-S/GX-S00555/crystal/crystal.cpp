#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	vector<ll> a;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		ll energy;
		cin>>energy;
		a.push_back(energy);
	}
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	sort(a.begin(),a.end());
	if(n<=16)
	{
		ll ans=1,max=0,rem=m;
		for(ll i=1;i<n;i++)
		{
			rem=m;
			ans=1;
			ll rei=i;
			vector<ll> minus;
			ll pre;
			for(ll j=0;j<i;j++)
			{
				pre=a[i]-a[j];
				minus.push_back(pre);
			}
			sort(minus.begin(),minus.end());
			ll k=0;
			while(rem>0&&rei>0)
			{
				rem-=minus[k];
				k++;
				rei--;
				ans++;
			}
			if(ans>max) max=ans;
			else if(ans<=max) i=n;
		}
		cout<<max;
		return 0;
	}
	else
	{
		ll ans=1,minus=0;
		ll level=a[0],rem=m;
		while(m>=0)
		{
			minus=0;
			if(level==a[ans]) ans++;
			else
			{
				minus=a[ans]-level;
				level=a[ans];
				m-=ans*minus;
			}
		}
		ll less=a[ans]-a[0],plus=0;
		for(ll i=0;i<n-ans;i++)
		{
			if(a[ans+i]-a[i]<less){
				less=a[ans]-a[i];
				plus=i;
			}
		}
		if(less==a[ans]-a[0]) cout<<ans;
		else
		{
			ll ans2=1,minus2=0;
			ll level2=a[plus];
			while(rem>=0)
			{
				minus2=0;
				if(level2==a[ans2+plus]) ans2++;
				else
				{
					minus2=a[ans2+plus]-level2;
					level2=a[ans2+plus];
					rem-=ans2*minus2;
				}
			}
			if(ans2>ans) cout<<ans2;
			else cout<<ans;
		}
	}
	return 0;
}
