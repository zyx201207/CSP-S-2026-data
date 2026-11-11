#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define min(x,y) (x<y)?x:y
inline int read()
{
	char c=getchar();int f=1,x=0;
	while(c<'0' || c>'9') {(c=='-')?(f=-1):0;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+(c-'0');c=getchar();}
	return x*f;
}

const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=505,M=5e5+5,Q=1e5+5,D=25;
int _C_,n,m,d,q,w[M];
ll dis[N][N];
struct IN{int i,n;};
vector<IN> v[M];

signed main()
{
	fastio;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	_C_=read(),n=read(),m=read(),d=read(),q=read();
//	cin>>_C_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		w[i]=read();
//		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k=read();
//		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a=read(),t=read();
//			int a,t;cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=v[i].size();
		if(len<=1) continue;
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++)
			{
				IN jj=v[i][j],kk=v[i][k];
				dis[jj.i][kk.i]=dis[kk.i][jj.i]=
					min(dis[jj.i][kk.i],(ll)(jj.n+kk.n));
			}
	}
	
//	for(int i=1;i<=n;i++)
//	{for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';cout<<'\n';}
//	cout<<'\n';
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)if(i!=k)
			for(int j=1;j<=n;j++)if(j!=i && j!=k)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				
//	for(int i=1;i<=n;i++)
//	{for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';cout<<'\n';}
	
	while(q--)
	{
		int l=read(),r=read();
//		int l,r;cin>>l>>r; 
		ll ans=inf,lenl=v[l].size(),lenr=v[r].size();
		for(int i=0;i<lenl;i++)for(int j=0;j<lenr;j++)
		{
			IN ii=v[l][i],jj=v[r][j];
			ans=min(ans,dis[ii.i][jj.i]+ii.n+jj.n);
		}
		ans+=w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
