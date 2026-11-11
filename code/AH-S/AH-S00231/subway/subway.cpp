#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[500010],cnt[500010],u[500010],v[500010],dis[500010];
vector<vector<pair<int,int>>> tu(500010);
//bool vis[500010];
void dijkstra(int st)
{
	memset(dis,0,sizeof(dis));
	dis[st]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
	p.push({0,st});
	while(!p.empty())
	{
		int qwe=p.top().first;
		int wer=p.top().second;
		p.pop();
		for(int i=0;i<tu[wer].size();i++)
		{
			int asd=tu[wer][i].first;
			int sdf=tu[wer][i].second;
			int nd=dis[wer]+sdf;
			if(nd<dis[wer])
			{
				dis[wer]=nd;
				p.push({nd,wer});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>u[i]>>v[i];
			cnt[u[i]]++;
			tu[u[i]].push_back({cnt[u[i]],v[i]});
			tu[cnt[u[i]]].push_back({u[i],v[i]});
			if(j>=2)
			{
				tu[cnt[u[j-1]]].push_back({cnt[u[j]],0});
				tu[cnt[u[j]]].push_back({cnt[u[j-1]],0});
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<tu[i].size();i++)
		{
			cout<<i<<" "<<tu[i][j].first<<" "<<tu[i][j].second<<endl;
		}
		cout<<endl;
	}*/
	while(q--)
	{
		int hjk,jkl;
		cin>>hjk>>jkl;
		dijkstra(hjk);
		cout<<w[hjk]+w[jkl]+dis[jkl]<<endl;
	}
}
