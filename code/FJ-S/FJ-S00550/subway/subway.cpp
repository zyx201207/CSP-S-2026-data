#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,as[500001],e,f,g,dis[501][501],out;
vector<long long>bs[600001],cs[600001];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>a>>b>>c>>d;
	for(int i=1;i<=b;i++)
	{
		cin>>as[i];
	}
	for(int i=1;i<=a;i++)
	{
		cin>>e;
		for(int j=1;j<=a;j++)
		{
			if(i!=j)dis[i][j]=dis[j][i]=1e18;
		}
		for(int j=1;j<=e;j++)
		{
			cin>>f>>g;
			bs[i].push_back(f+a);
			cs[i].push_back(g);
			bs[f+a].push_back(i);
			cs[f+a].push_back(g);
		}
	}
	for(int i=a+1;i<=a+b;i++)
	{
		for(int j=0;j<bs[i].size();j++)
		{
			for(int k=0;k<j;k++)
			{
				dis[bs[i][j]][bs[i][k]]=dis[bs[i][k]][bs[i][j]]=min(dis[bs[i][j]][bs[i][k]],cs[i][j]+cs[i][k]);
			}
		}
	}
	for(int k=1;k<=a;k++)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=d;i++)
	{
		cin>>e>>f;e+=a;f+=a;out=1e18;
		for(int j=0;j<bs[e].size();j++)
		{
			for(int k=0;k<bs[f].size();k++)
			{
				out=min(out,dis[bs[e][j]][bs[f][k]]+cs[e][j]+cs[f][k]);
			}
		}
		cout<<out+as[e-a]+as[f-a]<<'\n';
	}
	return 0;
}
