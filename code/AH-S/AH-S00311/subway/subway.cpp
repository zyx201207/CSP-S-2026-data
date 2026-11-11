#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> line;vector<ll> w;vector<vector<ll>> subway;
ll minn=LLONG_MAX;
void dfs(ll i,ll flag,ll l,vector<bool> vis,ll pre)
{
	if(i==flag) 
	{
			minn=min(pre+w[i],minn);
			return;
	}
	else
	{
		bool ok;
		if(l!=-1&&vis[l]==1) ok=1;
		else ok=0;
		if(l!=-1) vis[l]=1;
		 for(ll j=0;j<subway.size();j++)
		 {
		 	if(j!=l&&vis[l]!=1) dfs(i,flag,j,vis,pre+line[subway[i][j]][i]+(l==-1?w[i]:line[l][i]));
		 }
		 if(l!=-1&&ok==0)
		 {
		 	for(ll j=0;j<line[l].size();j++)
		 	{
		 		if(line[l][j]==-1) continue;
		 		dfs(j,flag,l,vis,pre+line[l][j]);

		 	}
		 }
	}

}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	line.resize(n+1,vector<ll>(d+1,-1));
	w.resize(m+1);
	for(ll i=1;i<=m;i++) cin>>w[i];
	subway.resize(n+1);
	for(ll i=1;i<=n;i++)
	{
		ll k;cin>>k;
		line[i].resize(k+1);
		for(ll j=1;j<=k;j++)
		{
			ll l,r;cin>>l>>r;
			line[i][l]=r;//xian zhong de ge zhan dian qing kuang 
			subway[l].push_back(i);//ge ge dian you guan de xian lu
		}
	}
	for(ll i=1;i<=q;i++)
	{
		vector<bool> f(n+1,0);
		ll l,r;cin>>l>>r;
		dfs(l,r,-1,f,0);
	}
	cout<<minn;

}