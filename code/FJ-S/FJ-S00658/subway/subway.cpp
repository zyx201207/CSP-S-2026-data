#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(i) cout<<"Debug "<<i<<' '
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define sc second
const int N=1145,M=1e6+10;
int C,n,m,d,q,w[M],a[N][N];
vector< pii >v[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		pii t;t.fi=i;
		for(int j=1,p;j<=k;j++) cin>>p>>t.sc,v[p].push_back(t);
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++) for(int k=0;k<v[i].size();k++)
		{
			if(j==k) continue;
			a[v[i][j].fi][v[i][k].fi]=min(v[i][j].sc+v[i][k].sc,a[v[i][j].fi][v[i][k].fi]);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=0x3f3f3f3f3f3f3f3fll;
		cin>>x>>y;
		for(int j=0;j<v[x].size();j++) for(int k=0;k<v[y].size();k++)
		{
			ans=min(ans,a[v[x][j].fi][v[y][k].fi]+v[x][j].sc+v[y][k].sc);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
 }

