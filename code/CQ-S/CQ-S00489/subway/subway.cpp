#include <bits/stdc++.h>
using namespace std;

bitset<500505> vis;
int sta[500005],d[500505],c,n,m,dd,q;
vector<pair<int,int> > a[500505];
struct node
{
	int x,y,id,ans=0;
	void read(int i)
	{
		cin>>x>>y;
		id=i;
	}
	bool operator<(node xx)const
	{
		return x<xx.x;
	}
}qry[100005];
bool cmp(node x,node y)
{
	return x.id<y.id;
}
void bfs(int x)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,x+n}),d[x+n]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto i:a[x])
		{
			if(d[i.first]>d[x]+i.second) d[i.first]=d[x]+i.second,q.push({d[i.first],i.first});
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>c>>n>>m>>dd>>q;
	for(int i=1; i<=m; i++) cin>>sta[i];
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,w;
			cin>>x>>w;
			a[i].push_back({x+n,w}),a[x+n].push_back({i,w});
		 } 
	}
	for(int i=1; i<=q; i++) qry[i].read(i); 
	sort(qry+1,qry+q+1);
	for(int i=1; i<=q; i++)
	{
		memset(d,0x3f,sizeof(d[0])*(n+m+2));
		vis.reset();
		bfs(qry[i].x);
		int j;
		for(j=i; qry[j].x==qry[i].x; j++) qry[j].ans=d[qry[j].y+n]+sta[qry[j].x]+sta[qry[j].y];
		i=j-1;
	}
	sort(qry+1,qry+q+1,cmp);
	for(int i=1; i<=q; i++) cout<<qry[i].ans<<'\n';
	return 0;
}
//地铁双向任意通行 

