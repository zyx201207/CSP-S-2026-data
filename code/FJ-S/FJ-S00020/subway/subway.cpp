//tai hao le wo hui zuo T2 le
//wo you jiu le
//T2 idk 100?
//QAQ bie gua le a
//rp qi zuo yong le ha ha
#include <iostream>
#include <cstdio>
#include <vector>
//#include <ctime>
using namespace std;
const int N=5e5+10;
const long long inf=4.2e18; 
vector<pair<int,int> > ve[N];
long long dp[510][510];
int w[N];
int rd()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar(); 
	}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
//		scanf("%d",&w[i]);
		w[i]=rd();
	}
	for(int i=1;i<=n;i++)
	{
		int k;
//		scanf("%d",&k);
		k=rd();
		for(int j=1;j<=k;j++)
		{
			int a,b;
//			scanf("%d%d",&a,&b);
			a=rd();
			b=rd();
			ve[a].push_back(make_pair(i,b));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=inf;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)ve[i].size();j++)
		{
			for(int k=0;k<(int)ve[i].size();k++)
			{
				int l=ve[i][j].first,r=ve[i][k].first,w=ve[i][j].second+ve[i][k].second;
//				cout<<l<<" "<<r<<" "<<w<<endl;
				dp[l][r]=min(dp[l][r],(long long)w);
				dp[r][l]=min(dp[r][l],(long long)w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	double s=clock();
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			printf("0\n");
			continue;
		}
		long long ans=2*inf;
		for(int i=0;i<(int)ve[a].size();i++)
		{
			for(int j=0;j<(int)ve[b].size();j++)
			{
//				cout<<ve[a][i].second+ve[b][j].second<<" "<<dp[ve[a][i].first][ve[b][j].first]<<endl;
				ans=min(ans,1ll*w[a]+w[b]+ve[a][i].second+ve[b][j].second+dp[ve[a][i].first][ve[b][j].first]);
			}
		}
		printf("%lld\n",ans);
	}
//	double t=clock();
//	cerr<<t-s<<"ms"<<endl;
	return 0;
}
