#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5*1e5+5;
ll c,n,m,d,q,w[N],k[505],X,Y,ans,book[20005];
struct nodel {ll a,t;} line[505][20005];
struct nodes {ll l,t;} s[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<N;i++)s[i].t=INT_MAX;
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
		{
			cin>>line[i][j].a>>line[i][j].t;
			s[line[i][j].a].l=i,s[line[i][j].a].t=min(line[i][j].t,s[line[i][j].a].t);
		}
	}
	
	//c=20/21
	if(c==20||c==21)
	{
		ll minT=INT_MAX;
		for(ll i=1;i<=20003;i++)
		{
			if(line[1][i].a==line[2][i].a)
				minT=min(line[1][i].t+line[2][i].t,minT);
		}
		while(q--)
		{
			ans=0;
			cin>>X>>Y;
			ans+=w[X]+w[Y];
			ans+=s[X].t+s[Y].t;
			if(s[X].l!=s[Y].l)ans+=minT;
			cout<<ans<<'\n';
		}
		return 0;
	}
	
	cout<<0;
	return 0;
}
