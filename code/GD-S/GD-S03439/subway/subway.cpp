#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=2e3+10;
struct node
{
	int id,c;
	node(){}
	node(int _id,int _c)
	{
		id=_id;
		c=_c;
	}
	bool operator<(const node &x)const
	{
		return x.c<c;
	}
};
int gt[N];
vector<node> att[N];
vector<node> a[N];
bool vis[M][M];
int dis[M][M];
void dijk(int beg,int ckx)
{
	//cout<<ckx<<endl;
	priority_queue<node> pq;
	pq.push({beg,0});
	vis[beg][ckx]=1;
	dis[beg][ckx]=0;
	while(!pq.empty())
	{
		node now=pq.top();
		pq.pop();
		//cout<<now.id<<" "<<now.c<<endl;
		for(int i=0;i<a[now.id].size();i++)
		{
			node t=a[now.id][i];
			if(vis[t.id][ckx])continue;
			dis[t.id][ckx]=t.c+now.c;
			//cout<<"--"<<t.id<<" "<<ckx<<endl;
			vis[t.id][ckx]=1;
			pq.push({t.id,dis[t.id][ckx]});
		}
	}
	//cout<<"\n\n\n\n\n\n";
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int t;
		cin>>t;
		gt[i]=t; 
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int tid,tc;
			cin>>tid>>tc;
			att[tid].push_back({m+m+i,tc});
			att[m+m+i].push_back({tid,tc});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<att[m+m+i].size();j++)
		{
			int t=att[m+m+i][j].id;
			int tc=att[m+m+i][j].c;
			if(att[t].size()>1)
			{
				a[t].push_back({m+m+i,tc});
				a[m+m+i].push_back({t,tc});
				//cout<<t<<" "<<m+m+i<<endl;;
			}
		}
	}memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dijk(m+m+i,m+m+i);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[m+m+i].size();j++)
		{
			dijk(a[m+m+i][j].id,a[m+m+i][j].id);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
		{
			cout<<0<<endl;
			continue;
		}
		int ans=gt[x]+gt[y];
		int gtx=att[x].size();
		int gty=att[y].size();
		
		if(gtx>1&&gty>1)
		{
			ans+=dis[y][x];
		}
		if(gtx>1&&gty<=1)
		{
			ans+=dis[att[y][0].id][x];
			ans+=att[y][0].c;
		}
		if(gtx<=1&&gty>1)
		{
			ans+=dis[y][att[x][0].id];
			ans+=att[x][0].c;
		}
		if(gtx<=1&&gty<=1)
		{
			ans+=dis[att[y][0].id][att[x][0].id];
			ans+=att[x][0].c;
			ans+=att[y][0].c;
		}
		
		cout<<ans<<endl;
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
