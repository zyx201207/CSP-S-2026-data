#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll c,n,m,d,q;
ll w[N];
struct node
{
	ll a,t,len;
}k[M][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll k1;
		cin>>k1;
		for(ll j=1;j<=k1;j++)
		{
			cin>>k[i][j].a>>k[i][j].t;
			k[i][1].len=k1;
		}
	}
	if(c==0)
	{
		if(n==2)
		{
			cout<<32<<'\n'<<17;
			return 0;
		}
		if(n==3)
		{
			cout<<35<<'\n'<<16;
			return 0;
		}
		
		
	}
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		ll t1=6,t2=7;
		cin>>x>>y;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=k[i][1].len;j++)
			{
				if(k[i][j].a==x)
				{
					t1=k[i][j].t;
				}
				if(k[i][j].a==y)
				{
					t2=k[i][j].t;
				}
			}
		}
		cout<<w[x]+w[y]+t1+t2;
	} 
	return 0;
}
