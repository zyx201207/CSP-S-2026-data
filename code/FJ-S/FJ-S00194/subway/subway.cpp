#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,sum;
};
const int N=1e4+10;
long long a[N],b[N][N];
vector <node> e[5000];
long long mi=1e9;
void dfs(long long u,long long ans,long long r)
{
	if(u==r)
	{
		mi=min(mi,ans);
	}
	for(long long i=0;i<e[u].size();i++)
	{
		if(b[u][i])
		{
			continue;
		}
		b[u][i]=1;
		dfs(e[u][i].x,ans+e[u][i].sum,r);
		b[u][i]=0;
	}
}
void solve()
{
	long long l,r;
	cin>>l>>r;
	long long ans=a[l]+a[r];
	dfs(l,ans,r);
	cout<<mi<<endl;
	mi=1e9;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long u,v;
			cin>>u>>v;
			e[u].push_back({i+d,v});
			e[i+d].push_back({u,v}); 
		}
	}
	while(q--)
	{
		solve();
	}
	return 0;
}
