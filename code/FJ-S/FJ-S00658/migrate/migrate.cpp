#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(i) cout<<"Debug "<<i<<' '
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define sc second
const int N=5114;
int C,T,n,d,a[N],dis[N][N],c[N][N];
inline void sol()
{
	cin>>n>>d;int ans=0;
//	memset(dis,0x3f,sizeof(dis));
//	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0x3f3f3f3f3f3f3f3fll,c[i][j]=0;
	for(int i=1;i<=n;i++) cin>>a[i];dis[n][n]=0;c[n][n]=1;
	for(int i=n-1;i>=1;i--) 
	{
		dis[i][i]=0;c[i][i]=1;
		int j=i+1;
		for(;j<=n;j++)
		{
			if(a[j]-a[i]>d) break;
			dis[i][j]=1;c[i][j]=1;
		}
		for(int jj=j;jj<=n;jj++)
		{
			for(int k=i+1;k<j;k++)
			{
				if(dis[k][jj]+1<dis[i][jj])
				{
					dis[i][jj]=dis[k][jj]+1;c[i][jj]=c[k][jj];
				}
				else if(dis[k][jj]+1==dis[i][jj])c[i][jj]+=c[k][jj];
			}
		}
		for(int j=i;j<=n;j++) ans+=(c[i][j]==2&&dis[i][j]<=n);
		for(int j=i;j<=n;j++) c[i][j]=min(3ll,c[i][j]);
//		debug(i)<<j<<'\n';
//		for(int j=i+1;j<=n;j++) cout<<dis[i][j]<<' '<<c[i][j]<<"  ";
//		cout<<'\n';
	}
	cout<<ans<<'\n';
 } 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--) sol();
 }

