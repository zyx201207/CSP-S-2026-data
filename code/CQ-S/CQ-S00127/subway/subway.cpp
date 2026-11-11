#include<bits/stdc++.h>
using namespace std;
int read()
{
	int res=0;
	while(1){
		char c=getchar();
		if('0'<=c and c<='9')
		{
			res=c-'0';
			break;
		}
	}
	while(1) {
		char c=getchar();
		if('0'<=c and c<='9')
			res*=10,res+=c-'0';
		else
			break;
	}
	return res;
}
const int N=5e5+510,M=510;
vector<pair<int,int>>e[N];
int w[N];
long long dist[M][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		while(k--)
		{
			int v=read(),cost=read();
			e[v].push_back({i,cost});
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dist[i][j]=1e16;

	for(int i=1;i<=m;i++)
	{
		int s=e[i].size();
		for(int j=0;j<s;j++)
			for(int k=j+1;k<s;k++)
				dist[e[i][k].first][e[i][j].first]=dist[e[i][j].first][e[i][k].first]=min(dist[e[i][j].first][e[i][k].first],1ll*e[i][j].second+e[i][k].second);
	}

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=i+1;j<=n;j++)
					if(j!=k)
						dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
	
	while(q--)
	{
		int a=read(),b=read();
		long long ans=LONG_LONG_MAX;
		for(auto xa:e[a])
			for(auto xb:e[b])
				ans=min(ans,1ll*xa.second+dist[xa.first][xb.first]+xb.second);
		cout<<ans+w[a]+w[b]<<"\n";
	}
	
	return 0;
}
