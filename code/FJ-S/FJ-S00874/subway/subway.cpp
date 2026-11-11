#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define f1 first
#define s2 second
ll c,n,m,d,q,w[500005];
vector<pii> g[500505];//1~m:站 m+1~m+n:线
vector<pii> qu(0);
vector<ll> s(0),t[500505];
ll hp(pii p)
{
	return p.first<<32|p.second;
}
ll rd()
{
	ll ans=0,f=1;
	char c;
	do c=getchar();
	while(!isdigit(c)&&c!='-');
	if(c=='-')f=-1;
	else ans+=c-'0';
	while(1)
	{
		c=getchar();
		if(!isdigit(c))break;
		ans*=10;ans+=c-'0';
	}
	return ans*f;
}
int main()
{
#ifndef zhengyi
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	/*
	freopen("E:\\csps-new\\down\\subway\\subway5.in","r",stdin);
	freopen("subway.out","w",stdout);
	//*/
	ios::sync_with_stdio(0);
	cout.tie(0);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)w[i]=rd(),g[i].push_back({0,0});
	for(int i=1;i<=n;i++)
	{
		ll k=rd();
		g[m+i].push_back({0,0});//小心初始化
		for(int j=1;j<=k;j++)
		{
			ll x=rd(),t=rd();
			g[m+i].push_back({x,t});
			g[x].push_back({m+i,t});//建无向边，小心编号
			
		}
	}
	unordered_map<ll,ll> ans;
	for(int i=1;i<=q;i++)
	{
		ll x=rd(),y=rd();
		s.push_back(x);
		t[x].push_back(y);
		qu.push_back({x,y});
		
	//	cout<<dij(s,t)+w[s]+w[t]<<"\n";
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());//注意这里
	if(12<=c&&c<=15)
	{
		for(int x:s)
		for(int y:t[x])
		{
			vector<ll> f(m+n+5,4e18);
			vector<bool> vis(m+n+5,0);
			priority_queue<pii,vector<pii>,greater<pii> > q;
			q.push({0,x});
			f[x]=0;
			while(q.size())
			{
				pii p=q.top();
				q.pop();
				ll nd=p.f1,u=p.s2;
				if(vis[u])continue;
				if(u==y)break;
				vis[u]=1;
				for(pii e:g[u])
				{
					ll v=e.f1,w=e.s2;
					if(w+nd<f[v])
					{
						f[v]=w+nd;
						q.push({f[v],v});
					}
				}
			}
			ans[hp({x,y})]=f[y]+w[x]+w[y];
		}
	}
	else
	{
		for(int x:s)
		
		{
			vector<ll> f(m+n+5,4e18);
			vector<bool> vis(m+n+5,0);
			priority_queue<pii,vector<pii>,greater<pii> > q;
			q.push({0,x});
			f[x]=0;
			while(q.size())
			{
				pii p=q.top();
				q.pop();
				ll nd=p.f1,u=p.s2;
				if(vis[u])continue;
				vis[u]=1;
				for(pii e:g[u])
				{
					ll v=e.f1,w=e.s2;
					if(w+nd<f[v])
					{
						f[v]=w+nd;
						q.push({f[v],v});
					}
				}
			}
			for(int y:t[x])ans[hp({x,y})]=f[y]+w[x]+w[y];
		}
	}
	for(pii p:qu)
	{
		cout<<ans[hp(p)]<<"\n";
	}
	return 0;
}

