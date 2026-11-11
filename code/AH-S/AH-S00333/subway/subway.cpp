#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e2+10,NN=5e5+10;
struct S
{
	ll v,w,num;
};
ll w[NN],t[N][NN/10],y[N],b[N*10][N*10],f[NN],f2[NN];
vector<S>g[N*10];
void dij(ll x)
{
	priority_queue<pair<ll,ll>>pq;
	memset(f,0,sizeof(f));
	pq.push({0,x});
	b[x][x]=0;
	while(!pq.empty())
	{
		pair<ll,ll>su=pq.top();
		pq.pop();
		f[su.second]=1;
		for(S i:g[su.second])
		{
			if(b[x][su.second]+i.w<b[x][i.v]&&!f[i.v])
			{
				b[x][i.v]=b[x][su.second]+i.w;
				pq.push({b[x][i.v]*-1,i.v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		for(ll j=1;j<=x;j++)
		{
			cin>>y[j]>>t[i][j];
		}
		for(ll j=1;j<=x;j++)
		{
			for(ll k=j+1;k<=x;k++)
			{
				g[y[j]].push_back({y[k],t[i][k]+t[i][j],i});
				g[y[k]].push_back({y[j],t[i][k]+t[i][j],i});
			}
		}
	}
	memset(b,0x3f,sizeof(b));
	for(ll i=1;i<=p;i++)
	{
		ll star,fini;
		cin>>star>>fini;
		if(!f2[star])dij(star);
		f2[star]=1;
		cout<<b[star][fini]+w[star]+w[fini]<<"\n";
	}
}
