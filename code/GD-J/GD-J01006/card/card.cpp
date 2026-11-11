#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll a[N];
ll n,m;
ll vis[N]={};
map<ll,ll>mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll start=1;start<=n;start++)
	{
		vector<ll>vt;
		for(ll i=start;i<=n;i++){
			vt.push_back(a[i]);
			vis[a[i]]++;
			if(vis[a[i]]>=2)
			{
				for(ll j=0;j<vt.size();j++)
				{
					if(vt[j]==a[i])
					{
						for(ll t=j;t<vt.size();t++)
						{
							vt.pop_back();
						}
						break;
					}
				}
			}
		}
		for(ll i=1;i<=m;i++)
		{
			vis[i]=0;
		}
		ll flag=0;
		for(ll i=0;i<vt.size();i++)
		{
			mp[vt[i]]++;
//			cout<<vt[i]<<' ';
		}
//		cout<<'\n';
	}
	for(ll i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}
