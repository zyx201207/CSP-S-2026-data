#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,a[2000005],dist[305][305],r[305][305];
bool f[305],en[305][305];
vector<ll>e[305];
void solve1()
{
	ll t=d/(a[2]-a[1]);
	if(t==0)cout<<0;
	else cout<<n-t*2+1;
	cout<<'\n';
}
void solve2()
{
	memset(dist,0x3f,sizeof dist);
	memset(en,0,sizeof en);
	memset(r,0,sizeof r);
	for(ll i=1;i<n;i++)
	{
		e[i].clear();
		for(ll j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d)
			{
				e[i].push_back(j);
				//cout<<i<<' '<<j<<'\n';
				r[i][j]=1;
			}
	}
	for(int i=1;i<=n;i++)
	{
		queue<ll>q;
		memset(f,0,sizeof f);
		q.push(i);
		dist[i][i]=0;
		f[i]=1;
		while(q.size())
		{
			ll u=q.front();
			q.pop();
			for(auto v:e[u])
			{
				if(f[v])continue;
				en[i][v]=1;
				dist[i][v]=dist[i][u]+1;
				//cout<<i<<' '<<v<<' '<<u<<' '<<dist[i][u]<<'\n';
				f[v]=1;
				q.push(v);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1+i;j<=n;j++)
		{
			cout<<dist[i][j];
			cout<<' ';
		}
		cout<<'\n';
	}*/
	//cout<<dist[1][4];
	for(ll k=2;k<n;k++)
	{
		for(ll i=1;i<k;i++)
		{
			for(ll j=k+1;j<=n;j++)
			{		
				//cout<<i<<' '<<k<<' '<<j<<"    ";
				//cout<<dist[i][k]<<' '<<dist[k][j]<<' '<<dist[i][j]<<'\n';
				if(dist[i][k]+dist[k][j]!=dist[i][j]||!en[i][j]||!en[i][k]||!en[k][j])continue;		
				r[i][j]+=r[i][k]*r[k][j];
				//cout<<i<<' '<<k<<' '<<j<<"    ";
				//cout<<r[i][k]<<' '<<r[k][j]<<' '<<r[i][j]<<'\n';
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			//cout<<r[i][j]<<' ';
			if(r[i][j]==2)
			{
				ans++;
				//cout<<i<<' '<<j<<'\n';
			}
		}
		//cout<<'\n';
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll t,c;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12)solve1();
		else solve2();
	}
	return 0;
}
