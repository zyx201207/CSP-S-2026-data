#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
const int N=5e5+5;
bool fq=false
int c,n,m,d,q,x[N/5],y[N/5];
vector<pair<int,int>> g[N],ans[N];
ll Cyrene,w[N],k,a[N],t[505][N];
void dfs(int u,int l,int df,int id)
{
	ans[id].pb({u,l});
	if(u==df) {fq=true;return ;}
	for(auto it:g[u])
	{
		int v=it.f;
		int vl=it.s;
		dfs(v,vl,df,id);
		if(fq) return ;
	}
}
void solve()
{
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[k][j];
		for(int j=1;j<k[i];j++)
		{
			g[a[j]].pb({a[j+1],k[i]});
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		dfs(x[i],g[x[i]][1].s,y[i],i);
		fq=false;
	}
	for(int i=1;i<=q;i++)
	{
		Cyrene=w[x]+w[y];
		for(int j=1;j<ans[i].size();j++)
		{
			if(ans[i][j].s!=ans[i][j-1].s) Cyrene+=t[ans[i][j].s][ans[i][j-1].f]+t[ans[i][j-1].s][ans[i][j-1].f];
		}
		cout<<Cyrene<<'\n';
	}
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	int T=1;
	while(T--) solve();
	return 0;
} 
