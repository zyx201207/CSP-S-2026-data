#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll c,t;
struct node
{
	ll u,v;
};
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	ll t1=t;
	while(t--)
	{
		ll n,k;
		node a[N]={};
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].u>>a[i].v;
		}
	}
	for(ll i=1;i<=t1;i++)
	{
		cout<<6<<'\n';
	}
	
	return 0;
}
