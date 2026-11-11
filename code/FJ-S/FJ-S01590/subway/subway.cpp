#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5,maxm2=500,maxk=5005,maxd=25,maxq=100005;
int c,n,m,d,q;
int w[maxm];
int k[maxn];
int a[maxn][maxk],t[maxn][maxk];
int x[maxq],y[maxq];
int dist[maxm2][maxm2];
map<pair<int,int>,int> vis;
vector<pair<int,int> > st[maxm];
#define mp make_pair
#define val first
#define pos second
int viss[maxm];
int bfs(int l,int r)
{
	int ans=0x3f3f3f3f;
	priority_queue<pair<int,int> > pq;
	pq.push(mp(0,l));
	while(pq.size()!=0)
	{
		pair<int,int> x=pq.top();pq.pop();
		if(x.second==r)
		{
			ans=min(ans,-x.val+w[l]+w[r]);
		}
		if(viss[x.pos])continue;
		viss[x.pos]=1;
		for(auto i:st[x.pos])
		{
			int xx=i.first,yy=i.second;   //xx=nowx
			for(int j=1;j<=k[xx];j++)
			{
				int nowpos=a[xx][j],nowval=t[xx][j];
//				if(x.pos==nowpos)continue;
				if(!vis[mp(x.pos,nowpos)])
				{
					vis[mp(x.pos,nowpos)]=vis[mp(nowpos,x.pos)]	;
					if(!vis[mp(x.pos,nowpos)])
					{
						vis[mp(x.pos,nowpos)]=0x3f3f3f3f;
						vis[mp(nowpos,x.pos)]=0x3f3f3f3f;
					}
				}
				if(vis[mp(x.pos,nowpos)]>-x.val+t[xx][j]+t[xx][yy]+w[l]+w[nowpos])
				{
					vis[mp(x.pos,nowpos)]=-x.val+nowval+t[xx][yy]+w[l]+w[nowpos];
					vis[mp(nowpos,x.pos)]=-x.val+nowval+t[xx][yy]+w[l]+w[nowpos];
					pq.push(mp(-vis[mp(x.pos,nowpos)]+w[nowpos]+w[l],nowpos));
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>w[i];
//	cout<<"w done\n";
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
//		cout<<"k[ "<<i<<" ] : "<<k[i]<<endl;
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			st[a[i][j]].emplace_back(mp(i,j));
		}
	}
	if(c<=8)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)dist[i][j]=0x3f3f3f3f;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				for(int _=j;_<=k[i];_++)
				{
					dist[a[i][j]][a[i][_]]=min(dist[a[i][j]][a[i][_]],w[a[i][j]]+t[i][j]+t[i][_]+w[a[i][_]]);
					dist[a[i][_]][a[i][j]]=min(dist[a[i][_]][a[i][j]],w[a[i][j]]+t[i][j]+t[i][_]+w[a[i][_]]);
	//				mk[a[i][j]][a[i][_]]=min(mk[a[i][j]][a[i][_]],t[i][j]+t[i][_]);
	//				mk[a[i][_]][a[i][j]]=min(mk[a[i][_]][a[i][j]],t[i][j]+t[i][_]);
				}
			}
		}
		
		for(int kk=1;kk<=m;kk++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(dist[i][kk]==0x3f3f3f3f||dist[kk][j]==0x3f3f3f3f)continue;
					dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]-2*w[kk]);
	//				cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>x[i]>>y[i];
			cout<<dist[x[i]][y[i]]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
//		for(int _=1;_<=m;_++)viss[_]=0;
//		cout<<"dbg "<<viss[1]<<endl;
		cin>>x[i]>>y[i];
//		if(vis[mp(x[i],y[i])]||vis[mp(y[i],x[i])])
//		{
//			cout<<vis[mp(x[i],y[i])]<<'\n';
//			continue;
//		}
		cout<<bfs(x[i],y[i])<<'\n';
	}
	return 0;
}
/*
T2 subway 32/100 pts
15:53~16:36
floyd。
心态还行。2hours left.
感觉比J好（ 
看到n<=500以为floyd，发现m才是节点数。

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

67 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
