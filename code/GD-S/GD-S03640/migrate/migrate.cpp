#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++) 
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
const int N=100,inf=1e9;
int cid,t;
int n,d,x[N],g[N][N],f[N][N];
void dfs(int st,int w)
{
	if(w==n) return;
	rep(i,w+1,n)
		if(f[st][w]+1==f[st][i]&&x[i]-x[w]<=d)
			g[st][i]+=g[st][w],dfs(st,i);
}
void solve()
{
	memset(g,0,sizeof g),memset(f,0,sizeof f);
	rep(i,1,n)
	{
		f[i][i]=0;
		rep(j,i+1,n)
		{
			int ls=lower_bound(x+1,x+1+n,x[j]-d)-x;
			f[i][j]=f[i][ls]+1;
		}
	}
	rep(i,1,n)
		g[i][i]=1,dfs(i,i);
	int ans=0;
	rep(i,1,n)
		rep(j,1,n) ans+=(g[i][j]==2);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>t;
	while(t--)
	{
		cin>>n>>d;
		rep(i,1,n) cin>>x[i];
		solve(); 
	}
}
