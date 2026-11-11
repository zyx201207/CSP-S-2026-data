#include <bits/stdc++.h>
#define int long long
#define fir first
#define sec second
using namespace std;
const int N=5e5+5,M=505,inf=1e18;
int m,n,mx,q,va[N],a[M],b[M],nm,d[M][M],f[M][M];
vector<pair<int,int> >v[N];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>m>>m>>n>>mx>>q;
	for(int i=1;i<=n;i++) cin>>va[i];
	for(int x,y,w,i=1;i<=m;i++)
	{
		cin>>x;
		while(x--) cin>>y>>w,v[y].push_back({i,w});
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++) d[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		nm=0;
		for(auto j:v[i]) a[++nm]=j.fir,b[nm]=j.sec;
		for(int x=1;x<=nm;x++) for(int y=1;y<=nm;y++) d[a[x]][a[y]]=min(d[a[x]][a[y]],b[x]+b[y]);
	}
	memcpy(f,d,sizeof(d));
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;cin>>x>>y;int as=inf;
		for(auto i:v[x]) for(auto j:v[y]) as=min(as,i.sec+j.sec+f[i.fir][j.fir]);
		cout<<as+va[x]+va[y]<<'\n';
	}
	return 0;
}
