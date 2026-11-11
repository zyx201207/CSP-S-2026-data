#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int c,n,m,d,x,y,v[N],t,vis[N],pos[N],dis[N],head[N],cnt,k,sum,h,w[N],cnt2;
struct edge
{
	int to,next,dis;
}e[N*2];
struct node
{
	int pos,dis;
	bool operator <(const node &s)const
	{
		return s.dis<dis;
	}
};
struct node2
{
	int pos,dis,how;
}a[N*2];
priority_queue<node> q;
void add(int u,int v,int k)
{
	e[++cnt].to=v;
	e[cnt].dis=k;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dij(int s)
{
	q.push((node){s,0});
	dis[s]=0;
	while(!q.empty())
	{
		node op=q.top();
		q.pop();
		int x2=op.pos;
		if(vis[x2])continue;
		//cout<<x2;
		for(int i=head[x2];i;i=e[i].next)
		{
			int y2=e[i].to;
			if(dis[y2]>dis[x2]+e[i].dis)
			{
				dis[y2]=dis[x2]+e[i].dis;
				//cout<<e[i].dis<<endl;
				q.push((node){y2,dis[y2]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway,out","w",stdout);
	cin>>c>>n>>m>>d>>h;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[++cnt2].pos>>a[cnt2].dis;
//			cout<<a[cnt2].pos<<endl;
			a[cnt2].how=i;
		}
		sum+=k;
	}
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=sum;j++)
		{	
//			cout<<a[i].pos<<" "<<a[j].pos<<endl;
			if(i!=j and a[i].pos!=a[j].pos and a[i].how==a[j].how)
			{
				//cout<<a[i].pos<<a[j].pos<<endl;
				add(a[i].pos,a[j].pos,a[i].dis+a[j].dis);
				add(a[j].pos,a[i].pos,a[i].dis+a[j].dis);
			}
			else if(a[i].pos==a[j].pos and i!=j and a[i].how!=a[j].how)
			{
				for(int z=1;z<=sum;z++)
				{
					if(a[z].how==a[j].how and a[z].pos!=a[j].pos)
					{
//						cout<<a[i].pos<<a[z].pos<<a[i].how<<a[z].how<<endl;
						add(a[i].pos,a[z].pos,a[i].dis+a[j].dis+a[z].dis);
						add(a[z].pos,a[i].pos,a[i].dis+a[j].dis+a[z].dis);
					}
				}
			}
			
		}
	}
	for(int i=1;i<=h;i++)
	{
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
//	for(int i=1;i<=m;i++)
//	{
//		cin>>x>>y>>k;
//		add(x,y,k);
//		add(y,x,k);
//	}
//	dij(1);
//	cout<<dis[n];
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


Oct31==Dec25?
*/
	return 0;
}
