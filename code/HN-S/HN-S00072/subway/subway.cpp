#include<bits/stdc++.h>
using namespace std;


long long d,q,line_n,line_point[500005],dis[500005],n,m,start,final;
struct nd
{
	long long point,distance;
};
vector<nd>g[505];
queue<nd>qq;
void bfs()
{
	qq.push({start,0});
	dis[start]=0;
	while(qq.size())
	{
		auto cur=qq.front();
		qq.pop();
		dis[cur.point]=min(dis[cur.point],cur.distance);
		if(cur.point>m*3)
		{
			continue;
		}
		for(auto o:g[cur.point])
		{
			qq.push({o.point,o.distance+cur.distance});
		}
	}
}

int main()
{
//	freopen("E:/HN-S00072/subway/subway2.in","r",stdin);
//	freopen("E:/HN-S00072/subway.txt","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	short t;
	long long o;
	cin>>t;
	if(t==0)
	{
		t=1;
	}
	while(t--)
	{
		memset(dis,0x7f,sizeof(dis));
		cin>>n>>m>>d>>q;
		for(long long i=0; i<m; i++)
		{
			cin>>o;
			g[i].push_back({i+m,o});
			g[i+m].push_back({i,o});
		}
		for(long long i=0; i<n; i++)
		{
			cin>>line_n;
			for(long long j=0; j<line_n; j++)
			{
				cin>>line_point[j]>>o;
				g[line_point[j]+m].push_back({line_point[j]+2*m,o});
				g[line_point[j]+2*m].push_back({line_point[j]+m,o});
			}
			for(long long j=0; j<line_n; j++)
			{
				for(long long k=j+1; k<line_n; k++)
				{
					g[line_point[j]+2*m].push_back({line_point[k]+2*m,0});
					g[line_point[k]+2*m].push_back({line_point[j]+2*m,0});
				}
			}
		}
		for(int i=0; i<q; i++)
		{
			cin>>start>>final;
			bfs();
			cout<<dis[final]<<endl;
		}
	}
	return 0;
}

