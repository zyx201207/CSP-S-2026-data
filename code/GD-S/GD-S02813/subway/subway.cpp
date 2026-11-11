#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int c,n,m,d,q,w[500005],cnt,h[50000007],sum=1;
int dis[50000007],summ;
vector<pair<int,int> >v[50000007];
priority_queue<pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > >pq;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cout<<c<<n<<m<<d<<q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	summ=m;
	for(int i=1;i<=n;i++)
	{
		
		int k;
		cin>>k;
		summ+=k;
		for(int j=1;j<=k;j++)
		{
			int tt,t;
			cin>>tt>>t;
			//cout<<tt<<' '<<t<<' '<<m+sum<<endl;
			v[tt].push_back({m+sum,t});
			v[m+sum].push_back({tt,t});
			if(j>1)
			{
				//cout<<m+sum<<' '<<0<<' '<<m+sum-1<<endl;
				v[m+sum].push_back({m+sum-1,0});
				v[m+sum-1].push_back({m+sum,0});
			}
			sum++;
		}
	}
	for(int i=1;i<=q;i++)
	{	
		int xx,yy;
		cin>>xx>>yy;
		pq.push({xx,0});
		for(int i=1;i<=summ+10;i++)
		{
			dis[i]=1999999999;
			if(i==xx)dis[i]=0;
		}
		while(!pq.empty())
		{
			int x=pq.top().first;
			pq.pop();
			for(int i=0;i<v[x].size();i++)
			{
				//cout<<i<<' '<<v[x][i].first<<' '<<v[x][i].second<<endl;
				int y=v[x][i].first,z=v[x][i].second;
				if(dis[y]>dis[x]+z)
				{
					dis[y]=dis[x]+z;
					//cout<<x<<' '<<dis[x]<<endl;
					pq.push({y,dis[y]});
				}
			}
		}
		cout<<dis[yy]+w[xx]+w[yy]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
