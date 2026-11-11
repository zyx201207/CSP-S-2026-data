#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005];
void so1()
{
	ll ma=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1)
	{
		cout<<ma;
		return;
	}
	ma=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(i!=j&&(a[i]&a[j]>ma))
			{
				ma=a[i]&a[j];
			}
		}
	}
	cout<<ma;
}
void so2()
{
	ll ans=(1<<30),w=30;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=m;)
	{
		bool f;
		for(ll j=1;j<=n;j++)
		{
			if(ans==(ans&a[j]))
			{
				i++;
				f=1;
			}
		}
		if(!f)
		{
			ans-=(1<<w)-(1<<w-1);
		}
		w--;
	}
	cout<<ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m<=2&&n<=2000)so1();
	else so2();
	return 0;
}
