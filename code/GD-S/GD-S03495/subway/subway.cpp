#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int M=524288,N=512,inf=1e18;
int c,n,m,d,q,w[M],k[N],S[M],E[M],f[N][N];
map<int,int> e[N],down[M];
//e[i][j] i号地铁线若经过站j，站厅 <-(e[i][j])-> 站台 
//down[i][j] 站i若被j号地铁线经过，站厅 <-(e[i][j])-> 站台 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	For(i,m) cin>>w[i];
	For(i,n)
	{
		cin>>k[i];
		For(j,k[i])
		{
			int x,y;
			cin>>x>>y;
			e[i][x]=y;
			down[x][i]=y;
		}
	}
	For(i,q)
		cin>>S[i]>>E[i];
	
	memset(f,1,sizeof(f));
	For(i,n) f[i][i]=0;
	For(i,n) Fors(j,i+1,n)
		for(auto it:e[i])
		{
			int k=it.first;
			if(e[j].find(k)!=e[j].end())
				f[i][j]=min(f[i][j],e[i][k]+e[j][k]);
		}
	
	For(i,n) Fors(j,1,i-1)
		f[i][j]=f[j][i];
	
	For(k,n) For(i,n) if(i!=k)
		For(j,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	
	For(i,q)
	{
		int ans=inf;
		for(auto ds:down[S[i]])
			for(auto de:down[E[i]])
				ans=min(ans,w[S[i]]+ds.second+f[ds.first][de.first]+de.second+w[E[i]]);
		cout<<ans<<'\n';
	}
	return 0;
}
