#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],x[505];
vector<ll> xl[500005]; 
unordered_map<ll,ll> a[505],t[505];
ll dis[505][505],f[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>x[i];
		for(ll j=1;j<=x[i];j++)
		{
			ll A,T;
			cin>>A>>T;
			t[i][A]=T;
			xl[A].push_back(i);
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll x1=0;x1<xl[i].size();x1++)
		{
			for(ll x2=0;x2<xl[i].size();x2++)
			{
				ll d1=xl[i][x1],d2=xl[i][x2];
				if(d1==d2)dis[d1][d2]=dis[d2][d1]=0;
				else dis[d1][d2]=dis[d2][d1]=min(dis[d1][d2],t[d1][i]+t[d2][i]);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			f[i][j]=dis[i][j];
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(i==j)f[i][j]=0;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		ll l,r,ans=LLONG_MAX;
		cin>>l>>r;
		for(ll d1=0;d1<xl[l].size();d1++)
		{
			for(ll d2=0;d2<xl[r].size();d2++)
			{
				ans=min(ans,t[xl[l][d1]][l]+f[xl[l][d1]][xl[r][d2]]+t[xl[r][d2]][r]);
			}
		}
		cout<<w[l]+w[r]+ans<<"\n";
	}
	return 0;
}

