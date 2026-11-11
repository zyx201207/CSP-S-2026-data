//祝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP rp++

//~ 12:00签退成功! rp-=(-INT_MAX) (doge ~
//11:28 暴力36~56pts.

//CCF今年数据求水  
//义父!!! 

#include<bits/stdc++.h>
using namespace std;
#define write ios::sync_with_stdio(false);
#define by cin.tie(0);
#define __wanghc__ cout.tie(0);
#define ll long long

const ll N=5e5+10;
ll a[N],ans[N];
vector<ll> v;
bool vis[N];

int main()
{
	write by __wanghc__
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		a[i-1]=0;
		for(ll j=i;j<=n;j++)
		{
			v.push_back(a[j]);
			if(vis[a[j]]==1)
			{
				ll p=-1;
				do
				{
					v.pop_back();
					p=v.back();
					vis[p]=0;
				}while(p!=a[j]);
			}
			vis[a[j]]=1;
		}
		while(!v.empty())
		{
			ll p=v.back();
			v.pop_back();
			ans[p]++;
		}
		memset(vis,0,sizeof(vis));
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

//Trick or treat!
