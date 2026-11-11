#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll c,T,n,d;
ll a[2000001];
ll f[2000001];
ll g[2000001];
ll tf[2000001];
ll tg[2000001];
queue<ll> q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>d;
		ll now=0;
		a[0]=-2e18;
		for (ll i=1;i<=n;i++)cin>>a[i];
		ll ans=0;
		for (ll i=1;i<=n;i++)
		{
			while (q.size())q.pop();
			for (ll j=0;j<=n;j++)tg[j]=0;
			for (ll j=0;j<=n;j++)f[j]=g[j]=0;
			f[i]=0;g[i]=1;
			tg[0]=1;
			q.push(i);
//			cout<<i<<'\n';
			for (ll j=i+1;j<=n;j++)
			{
				while (q.size()&&a[q.front()]+d<a[j])
				{
//					if (i==2)cout<<q.front()<<'\n';
					tg[f[q.front()]]-=g[q.front()];
					q.pop();
				}
				if (q.empty())break;
				ll minn=f[q.front()];
				f[j]=minn+1;
				g[j]=tg[minn];
				tg[f[j]]+=g[j];
				if (g[j]==2)ans++;
				q.push(j);
//				if (n==5&&i==2)cout<<j<<':'<<minn<<' '<<tg[1]<<' '<<f[j]<<' '<<g[j]<<'\n';
//				cout<<f[j]<<' '<<g[j]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

