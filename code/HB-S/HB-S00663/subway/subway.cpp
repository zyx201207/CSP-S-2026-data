#include <bits/stdc++.h>
using namespace std;

#define int long long

int c,n,m,d,q;
int k[1005];
int w[1005];
int t[1005][1005];
int in_[1005][1005];

struct nude
{
	int w,t;
};
vector<nude> mapp[1005];

int ans[1005][1005];

int dis[1005];
bool book[1005];
void dijkstra(int x)
{
	memset(dis,0x3f,sizeof(dis));
	memset(book,false,sizeof(book));
	dis[x]=0;
	
	for(int i=1;i<=m;++i)
	{
		int id=0,minn=0x3f3f3f3f;
		for(int j=1;j<=m;++j)
		{
			if(minn>dis[j]&&book[j]==false)
			{
				id=j;
				minn=dis[j];
			}
		}
		book[id]=true;
		
		//cout<<id<<endl;
		
		for(int j=0;j<mapp[id].size();++j)
		{
			int w=dis[id];
			int v=mapp[id][j].t;
			//cout<<mapp[id][j].w<<" "<<w+v<<" "<<dis[mapp[id][j].w]<<endl;
			if(w+v<dis[mapp[id][j].w])
			{
				dis[mapp[id][j].w]=w+v;
			}
		}
		//cout<<endl;
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin>>in_[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=k[i];++j)
		{
			for(int l=1;l<=k[i];++l)
			{
				mapp[in_[i][j]].push_back({in_[i][l],t[i][l]+t[i][j]});
			}
		}
	}
	
	//for(int i=1;i<=m;i++)
	//{
		//cout<<i<<":"<<endl;
		//for(int j=0;j<mapp[i].size();j++)
		//{
			//cout<<"    "<<mapp[i][j].w<<" "<<mapp[i][j].t<<endl;
		//}
	//}
	for(int i=1;i<=m;++i)
	{
		dijkstra(i);
		for(int j=1;j<=m;++j)
		{
			ans[i][j]=dis[j];
		}
	}
	while(q)
	{
		--q;
		int s,e;
		cin>>s>>e;
		//for(int i=1;i<=m;i++)
		//{
		//	cout<<dis[i]<<" ";
		//}
		//cout<<endl;
		cout<<ans[s][e]+w[s]+w[e]<<endl;
	}
	return 0;
}
