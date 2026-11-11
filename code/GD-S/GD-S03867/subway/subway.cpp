#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=1010;
int c,m,n,d,q,w[N],dis[N][N],a[N][N],t[N][N],siz[N];
void init ()
{
	memset(dis,0x3f,sizeof dis);
	for (int i=0;i<=1001;i++) dis[i][i]=0;
}
void makeG () //建立图  
{
	for (int i=1;i<=n;i++) //线路  
	{
		if (siz[i]==1) continue ;
		for (int j=1;j<siz[i];j++) // 直达边 
		{
			dis[a[i][j]][a[i][j+1]]=min(dis[a[i][j]][a[i][j+1]],t[i][j]+t[i][j+1]); 
			dis[a[i][j+1]][a[i][j]]=min(dis[a[i][j+1]][a[i][j]],t[i][j]+t[i][j+1]); 
		}  
		dis[a[i][siz[i]]][a[i][siz[i]-1]]=min(dis[a[i][siz[i]]][a[i][siz[i]-1]],t[i][siz[i]]+t[i][siz[i]-1]);
	}
}
// 同一条线上都是 0 
// 换线需要   t[i][j]+t[i][j+1]   
void floyd ()
{
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
} 
int solve (int st,int ed)
{
	if (c>=7) return dis[st][ed]+w[st]+w[ed];
	return 0;
}
signed main  ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) 
	{
		int k;
		cin>>k;
		siz[i]=k;
		for (int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	makeG();
	floyd();
	while (q--)
	{
		int st,ed;
		cin>>st>>ed;
		cout<<solve(st,ed)<<endl;
	}
	return 0;
} 

