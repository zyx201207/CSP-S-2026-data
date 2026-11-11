#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll M=2e6+5;
ll c,t,n,k,ans;
struct node
{
	ll v,nxt;
}e[M<<1];
ll h[M],cnt;
void add(ll x,ll y)
{
	e[++cnt]={y,h[x]};
	h[x]=cnt;
}
bool f[M];
ll pos;
ll pcnt=0,nans;
void dfs(ll u,ll fa,ll pl)
{
	if(f[u]&&!f[fa]) pcnt++;
	if(e[h[u]].v==fa&&e[h[u]].nxt==0)
	{
		nans=max(nans,pl);
		return;
	}
	for(ll i=h[u];i;i=e[i].nxt)
	{
		ll x=e[i].v;
		if(x==fa) continue;
		if(f[x])
		{
			dfs(x,u,0);
			nans=max(nans,(pl+1)/2);
		}
		else dfs(x,u,pl+1);
	}
}
void dfg(ll u,ll cnt)
{
	if(cnt==k)
	{
		pcnt=nans=0; 
//		for(int i=1;i<=n;i++) cout<<f[i];
//		cout<<endl;
//		cout<<pos<<endl;
		dfs(pos,0,0);
//		cout<<pcnt<<endl;
		if(pcnt<=2) ans=min(ans,nans);
		return;
	}
	if(u==n+1) return;
	dfg(u+1,cnt);
	f[u]=1;
	pos=u;
	dfg(u+1,cnt+1);
	f[u]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=LLONG_MAX;
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) h[i]=0;
		for(int i=1;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			add(x,y),add(y,x);
		}
		pos=0;
		dfg(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

