#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(0)
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
const int D=25;
int T,n,m,ans,l,Taskid,d,k,x,y;
int w[M];
int cnt[M];
int z[M][D];
int t[M][D];
int f[N][N];
double st,ed;
signed main()
{
	// st=clock();
	// fre(subway);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Tie,cin>>Taskid>>n>>m>>d>>T;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n)
	{
		cin>>k;
		rep(j,1,k) cin>>x>>t[x][++cnt[x]],z[x][cnt[x]]=i;
		rep(j,1,n) f[i][j]=LLONG_MAX/3;
		f[i][i]=0;
	}
	rep(i,1,m) rep(j,1,cnt[i]) rep(k,j+1,cnt[i]) x=z[i][j],y=z[i][k],f[x][y]=min(f[x][y],t[i][j]+t[i][k]),f[y][x]=min(f[y][x],t[i][j]+t[i][k]);
	rep(k,1,n) rep(i,1,n) rep(j,1,n) if(i!=j&&i!=k&&j!=k) f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	// rep(i,1,n)
	// {
	// 	rep(j,1,n) cerr<<f[i][j]<<" ";
	// 	cerr<<'\n';
	// }
	while(T--)
	{
		cin>>x>>y,ans=LLONG_MAX;
		rep(i,1,cnt[x]) rep(j,1,cnt[y]) ans=min(ans,f[z[x][i]][z[y][j]]+t[x][i]+t[y][j]);
		ans+=w[x]+w[y],cout<<ans<<'\n';
	}
	// ed=clock();
	// cerr<<(ed-st)*1.0/CLOCKS_PER_SEC;
	return 0;
}//100pts