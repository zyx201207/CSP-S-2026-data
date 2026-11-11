#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#define p pair<long long,long long> 
using namespace std;
const long long N=5*1e5+1;
const long long M=501;
long long enter[N];
long long dis[M][M];
vector<p> v[N];
long long ans=0;
int c,m,n,d,q;
void F()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	return;
}
long long fin(int s,int e)
{
	long long ma=1e9;
	for(int i=0;i<v[s].size();i++)
	{
		for(int j=0;j<v[e].size();j++)
		{
			ma=min(ma,dis[v[s][i].first][v[e][j].first]+v[s][i].second+v[e][j].second);
		}
	}
	return ma;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>enter[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			dis[j][j]=0;
			long long a,b;
			cin>>a>>b;
			p l;
			l.first=i,l.second=b;
			v[a].push_back(l);
		}
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long a=0;a<v[i].size();a++)
		{
			for(long long b=a+1;b<v[i].size();b++)
			{
				dis[v[i][a].first][v[i][b].first]=dis[v[i][b].first][v[i][a].first]=min(dis[v[i][a].first][v[i][b].first],v[i][a].second+v[i][b].second);
			} 
		}
	}
	F();
	for(int i=1;i<=q;i++)
	{
		ans=0;
		int s,e;
		cin>>s>>e;
		ans+=enter[s]+enter[e];
		ans+=fin(s,e);
		cout<<ans<<endl;
	}
	return 0;
}
