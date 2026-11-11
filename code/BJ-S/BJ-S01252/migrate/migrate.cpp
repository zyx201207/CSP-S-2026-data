#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+7;
ll C,T;
ll n,d;
ll x[N],xx[N];
ll ans1=0;
struct node
{
	ll u,d;
};
vector<ll> step,a,b;
void dfs1(ll s,ll t,ll d)
{
	if(s==t)
	{
		if(d<ans1)
		{
			ans1=d;
			a=vector<ll>();
			ll len=step.size();
			for(ll i=0;i<len;i++)
			{
				a.push_back(step[i]);
			}
		}
		return;
	}
	for(ll i=s+1;i<=t;i++)
	{
		
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		ll ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
			xx[i]=x[i];
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
