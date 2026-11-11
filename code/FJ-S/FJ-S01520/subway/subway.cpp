#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=500005;
const long long INF=1e18;
long long point[N][N];
long long dis[N][N];
long long c,n,m,d,q;
int w[M],k[N],passby[M][21],cnt[M];
long long passdis[M][21];
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			point[i][j]=INF;
			dis[i][j]=INF;	
		}
	}
	for(int i=1;i<=n;i++) point[i][i]=0;
	for(int i=1;i<=m;i++) cnt[i]=0;
}
	
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			long long ai,ti;
			cin>>ai>>ti;
			cnt[ai]++;
			passby[ai][cnt[ai]]=i;
			passdis[ai][cnt[ai]]=ti;
		}
	}
	
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=j+1;k<=cnt[i];k++)
			{
				long long x=passby[i][j];
				long long y=passby[i][k];
				long long disxy=passdis[i][j]+passdis[i][k];
				point[x][y]=min(point[x][y],disxy);
				point[y][x]=min(point[y][x],disxy);
			}
		}
	}


	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
			{
				point[j][k]=min(point[j][k],point[j][i]+point[i][k]);
				point[k][j]=point[j][k];
			}


	for(int i=1;i<=q;i++)
	{
		long long start,dest;
		long long ans=INF;
		cin>>start>>dest;
		for(int j=1;j<=cnt[start];j++)
		{
			for(int k=1;k<=cnt[dest];k++)
			{
				long long subdis=point[passby[start][j]][passby[dest][k]];
				ans=min(ans,passdis[start][j]+passdis[dest][k]+subdis);
			}
		}
		cout<<ans+w[start]+w[dest];
		cout<<'\n';
	}
	return 0;
}
