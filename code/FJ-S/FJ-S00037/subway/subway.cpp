#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
const int N=500000;
const long long inf=0x3f3f3f3f3f3f3f3fLL;
struct node
{
	int to,line;
	long long weight;
	node(int t,int l,long long w):to(t),line(l),weight(w){
	}
};
inline long long read()
{
	long long f=1,x=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct cmp
{
	bool operator()(const node &a,const node &b)
	{
		return a.weight>b.weight;
	}
};
int c,n,m,d,q;
map<pair<int,int>,long long> mp;//a到第b个站台 
vector<long long> w;
vector<vector<node> > v; 
void dijkstra(int x,int y)
{
	priority_queue<node,vector<node>,cmp> pq;
	bool visited[m+1][n+1]={false};
	long long dist[m+1][n+1];
	memset(dist,inf,sizeof(dist));
	dist[x][0]=0;//x到0号线站台
	pq.push(node(x,0,0)); 
	while(!pq.empty())
	{
		int now=pq.top().to;
		int nowline=pq.top().line;
		pq.pop();
		if(visited[now][nowline])
			continue;
		visited[now][nowline]=true;
		for(int i=0;i<v[now].size();i++)
		{
			pair<int,int> p1,p2;
			if(nowline!=v[now][i].line)//换乘了 
			{
				if(now!=x)
				{
					p1.first=now;
					p1.second=nowline;
					p2.first=now;
					p2.second=v[now][i].line;
				}
				else
				{
					p1.first=x;
					p1.second=v[now][i].line;
					p2.first=0;
					p2.second=0;
				}
				if(dist[now][nowline]+mp[p1]+mp[p2]<dist[v[now][i].to][v[now][i].line])
				{
					dist[v[now][i].to][v[now][i].line]=dist[now][nowline]+mp[p1]+mp[p2];
					pq.push(node(v[now][i].to,v[now][i].line,dist[v[now][i].to][v[now][i].line]));
				}
			}
			else
			{
				if(dist[now][nowline]<dist[v[now][i].to][nowline])
				{
					dist[v[now][i].to][v[now][i].line]=dist[now][nowline];
					pq.push(node(v[now][i].to,v[now][i].line,dist[v[now][i].to][nowline]));
				}
			}
		}
	}
	long long ans=inf;
	for(int i=1;i<=n;i++)
	{
		pair<int,int> p;
		p.first=y;
		p.second=i;
		ans=min(ans,dist[y][i]+mp[p]);
	}
	cout<<ans+w[x]+w[y]<<endl;
}
int main()
{
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	v.resize(m+1);
	w.resize(2*N+2);//N+i表示第i条线路的站厅 
	for(int i=1;i<=m;i++)//不要搞混m,n,m是点数，n是边数 
	{
		cin>>w[i];
	}
	pair<int,int> p;
	for(int i=1;i<=n;i++)
	{
		int k;
		k=read();
		int temp1=read();
		int temp99=read();
		p.first=temp1;
		p.second=i;
		mp[p]=temp99;//第temp1个站台走到第i号站厅所需时间 
		for(int j=2;j<=k;j++)
		{
			int temp2,temp3;
			temp2=read();
			temp3=read();
			v[temp1].push_back(node(temp2,i,0));
			v[temp2].push_back(node(temp1,i,0));
			p.first=temp2;
			p.second=i;
			mp[p]=temp3;
			temp1=temp2;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		dijkstra(x,y);
	}
}
