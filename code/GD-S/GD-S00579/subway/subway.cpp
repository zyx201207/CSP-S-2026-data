#include<bits/stdc++.h>
// #include<cassert>
using namespace std;
int c,n,m,d,q;
// class edge
// {
// public:
// 	int v,w,nxt;
// };
// class E
// {
// public:
// 	vector<edge>vec;
// 	vector<int>hd;
// 	int cnt;
// 	E():cnt(-1){}
// 	E(int n,int m):cnt(-1){hd.resize(n*m+1);}
// 	void add(int i,int j,int u,int v,int w)
// 	{
// 		cnt++;
// 		vec.push_back({v*j,w,hd[i*u]});
// 		hd[i*u]=cnt;
// 	}
// };
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1),k(n+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	// E eg(n,m);
	vector<vector<int>>t(n+1,vector<int>(m+1,0));
	vector<vector<int>>js(m+1);
	vector<vector<int>>dis(n*m+1,vector<int>(n*m+1,1e8));
	for(int i=1;i<=n*m;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		// t[i].resize(k[i]+1);
		int hd;
		cin>>hd;
		cin>>t[i][hd];
		js[hd].push_back(i);
		for(int j=1;j<k[i];j++)
		{
			int x;
			cin>>x;
			cin>>t[i][x];
			js[x].push_back(i);
			// dis[(i-1)*m+x][(i-1)*m+hd]=0;
			// dis[(i-1)*m+hd][(i-1)*m+x]=0;
			dis[(i-1)*m+x][(i-1)*m+hd]=0;
			dis[(i-1)*m+hd][(i-1)*m+x]=0;
			// dis[(i-1)*m+hd][(i-1)*m+x]=0;
			// dis[(i-1)*m+x][(i-1)*m+hd]=0;
			// assert(dis[(i-1)*m+x][(i-1)*m+hd]=dis[(i-1)*m+hd][(i-1)*m+x]=0);
			// eg.add(i,i,hd,x,0);
			// eg.add(i,i,x,hd,0);
		}
		// cout<<"sdf"<<endl;
	}
// cout<<"sdf"<<endl;
	for(int i=1;i<=m;i++)
	{
		// vector<int>::iterator it=js[i].begin();
		// for(;it!=js[i].end();it++)
		// {
		// 	vector<int>::iterator ii=it+1;
		// 	for(;ii!=js[i].end();ii++)
		// 	{
		// 		dis[(*it-1)*m+i][(*ii-1)*m+i]=dis[(*ii-1)*m+i][(*it-1)*m+i]=t[*it][i]+t[*ii][i];
		// 		// eg.add(*it,*ii,i,i,t[*it][i]+t[*ii][i]);
		// 		// eg.add(*ii,*it,i,i,t[*it][i]+t[*ii][i]);
		// 	}
		// }
		// if(js[i].size())
//		try{
		for(int u:js[i])
			for(int v:js[i])
			{
				if(u!=v)
				{
					// assert((u-1)*m+i<=n*m);assert((v-1)*m+i<=n*m);
					dis[(u-1)*m+i][(v-1)*m+i]=t[u][i]+t[v][i];
					dis[(v-1)*m+i][(u-1)*m+i]=t[u][i]+t[v][i];
				}
			}
//		}
//		catch(...){exit(-1);}
	// cout<<"dsasdfadf"<<endl;
	}
	for(int i=1;i<=n*m;i++)
		for(int u=1;u<=n*m;u++)
			for(int v=1;v<=n*m;v++)
				dis[u][v]=dis[v][u]=min(dis[u][v],dis[u][i]+dis[i][v]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=INT_MAX;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			ans=min(ans,dis[(i-1)*m+x][(j-1)*m+y]);
		}
		// cout<<ans<<' ';
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
