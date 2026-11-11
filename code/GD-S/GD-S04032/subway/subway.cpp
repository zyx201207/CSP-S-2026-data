#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7,M=505;
struct node{
	long long v,w,flag;
	bool operator<(const node t)const{
		return t.w<w;
	}
};
long long c,m,n,d,q,w[N],dis[M],vis[M];
vector<node>nod[N],E[M];
long long dij(long long x_,long long y)
{
	priority_queue<node>q;
	q={};
	long long ans=1e18+7;
	for(long long i=1;i<=m;i++)
	{
		dis[i]=1e18+7;
		vis[i]=0;
	}
	for(long long i=0;i<nod[x_].size();i++)
	{
		q.push({nod[x_][i].v,nod[x_][i].w,1});
//		cout<<nod[x_][i].v<<" "<<nod[x_][i].w<<endl;
		dis[nod[x_][i].v]=nod[x_][i].w;
	}
	for(long long i=0;i<nod[y].size();i++)
	{
		vis[nod[y][i].v]=nod[y][i].w;
//		cout<<nod[y][i].v<<" "<<nod[y][i].w<<endl;
	}
	while(!q.empty())
	{
		node x=q.top();
//		cout<<"SIZE"<<q.size()<<endl;
		q.pop();
		
		if(x.flag==0)
		{
//			for(long long i=0;i<nod[y].size();i++)
//			{
//				vis[nod[y][i].v]=0;
//			}
//			cout<<"!";
			return ans;
		}
		for(node k:E[x.v])
		{
//			cout<<dis[k.v]<<" "<<dis[x.v]+k.w<<endl;
			if(dis[k.v]>dis[x.v]+k.w)
			{
				dis[k.v]=dis[x.v]+k.w;
				q.push({k.v,dis[k.v],1});
			}
		}
//		cout<<"OOO"<<se[x.v][y];
		if(vis[x.v]!=0)
		{
			q.push({0,0,0});
			ans=min(ans,dis[x.v]+vis[x.v]);
		}
	}
//	cout<<"?";
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>c>>m>>n>>d>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=m;i++)
	{
		long long cnt;
		cin>>cnt;
		for(long long j=1;j<=cnt;j++)
		{
			long long x,t;
			cin>>x>>t;
			nod[x].push_back({i,t});
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<i<<":";
//		for(node k:nod[i])
//		{
//			cout<<k.v<<" ";
//		}
//		cout<<endl;
//	}
//	
//	cout<<"!";
	for(long long k=1;k<=n;k++)
	{
		for(long long i=0;i<nod[k].size();i++)
		{
			for(long long j=i+1;j<nod[k].size();j++)
			{
				E[nod[k][i].v].push_back({nod[k][j].v,nod[k][i].w+nod[k][j].w,1});
				E[nod[k][j].v].push_back({nod[k][i].v,nod[k][i].w+nod[k][j].w,1});
			}
		}
	}
//	for(long long i=1;i<=m;i++)
//	{
//		for(node k:E[i])
//		{
//			cout<<i<<" "<<k.v<<" "<<k.w<<endl; 
//		}
//	}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<'\n';
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
