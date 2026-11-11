#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
ll c,n,m,d,p;
ll w[M],a[N],b[2][N];
vector<pair<ll,ll> > l[N],h[N];
vector<ll> e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
//	cout << 1 << endl;
	for(int i=1;i<=n;i++)
	{
		ll k;
		scanf("%lld",&k);
//		cout << k << endl;
		for(int j=1;j<=k;j++)
		{
//			cout << k << endl;
			ll aa,bb;
			scanf("lld%lld",&aa,&bb);
			if(c>=20 && c<=21) b[i][bb]=aa;
			h[i].push_back({bb,aa});
			l[bb].push_back({i,aa});
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(b[1][i] && b[2][i]) a[i]=b[1][i]+b[2][i];
	}
	while(p--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=3e9;
		if(c>=20 && c<=21)
		{
			if(b[1][x] && b[1][y]) ans=min(ans,b[1][x]+b[1][y]);
			if(b[2][x] && b[2][y]) ans=min(ans,b[2][x]+b[2][y]);
			if(ans!=3e9)
			{
				printf("%lld\n",ans+w[x]+w[y]);
			 	continue;
			}
			ll mi=5e9;
			for(int i=1;i<=n;i++) mi=min(mi,a[i]);
			if(b[1][x])
			{
				printf("%lld\n",b[1][x]+b[2][y]+mi+w[x]+w[y]);			
			}  
			else
			{
				printf("%lld\n",b[2][x]+b[1][y]+mi+w[x]+w[y]);				
			}
			continue; 
		}
		if(c>=12 && c<=19)
		{
			
		}		
	}

	return 0;
}

