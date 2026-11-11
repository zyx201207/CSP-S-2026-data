//GZ-S00078 贵阳市新世界学校 王正彭 
/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005];
ll a[500005],t[500005];
struct ss
{
	ll a,t,i;
	ss(ll aa=0,ll ii=0,ll tt=0)
	{
		a=aa,i=ii,t=tt;
	}
};
vector<ss>vt[505];
bool vis[500005];
map<pair<ll,ll>,ll>mp;
void dij(ll st,ll en)
{
	priority_queue< pair<ll,ll> > q;
	q.push({0,st});
	ll ans=0x7ffffffffffffff;
	while(!q.empty())
	{
		ll now=q.top().second;
		ll sum=q.top().first;
		q.pop();
		if(now==en)
		{
			ans=min(ans,sum);
			continue;
		}
		vis[now]=1;
		for(int i=0;i<vt[now].size();i++)
		{
			ss x=vt[now][i];
			if(!vis[x.a])
				q.push({x.a,sum+mp[{now,x.i}]+x.t});
		}
	}
	cout<<ans+w[st]+w[en]<<'\n';
	return;
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++)
			{
				mp[{a[l],i}]=t[l];
				vt[j].push_back(ss(a[l],t[l],i));
			}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
}*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005];
ll x,y,ans;
ll c,n,m,d,q;
vector< pair<ll,ll> > vt[505]; 
bool vis[500005];
map< ll,vector<ll> > mp;
void dfs(ll pos,ll sum)
{
	if(pos==y)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<mp[pos].size();i++)
	{
		for(int j=0;j<vt[mp[pos][i]].size();i++)
		{
			ll a=vt[mp[pos][i]][j].first;
			ll t=vt[mp[pos][i]][j].second;
			if(!vis[a])
			{
				vis[pos]=1;
				dfs(a,sum+t);
				vis[pos]=0;
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			ll a,t;
			cin>>a>>t;
			vt[i].push_back({a,t});	
			mp[a].push_back(i);
		} 
	}
	while(q--)
	{
		ans=0x7ffffffffffffff;
		cin>>x>>y;
		dfs(x,0);
		cout<<ans<<'\n';
	}
	return 0;
}
