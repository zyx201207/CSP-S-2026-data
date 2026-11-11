#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
//#define int long long
int c,n,m,d,q;
const int N=505,M=5e5+5;
inline int read()
{
	char ch;
	int num=0,f=1;
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
		if(ch=='-')f=-1;
	}
	while(ch>='0'&&ch<='9')
	{
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num*f;
}
struct node
{
	int v,w;
	bool operator < (const node x)const
	{
		return w>x.w;
	}
};
vector<node> vec[N+M];
priority_queue<node> que;
int dis[N+M];
bool vis[N+M];
int w[N];
void dijkstra(int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	que.push({s,0});
	while(!que.empty())
	{
		node top=que.top();
		que.pop();
		int now=top.v;
		if(vis[now])continue;
		vis[now]=1;
		for(int i=0;i<vec[now].size();i++)
		{
			int to=vec[now][i].v,
				ww=vec[now][i].w;
			dis[to]=min(dis[to],dis[now]+ww);
			que.push({to,dis[to]});
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		k=read();
		for(int j=1;j<=k;j++)
		{
			a=read();
			t=read();
			vec[a].push_back((node){m+i,t});
			vec[m+i].push_back((node){a,t});
		}
	}
	int l,r;
	for(int i=1;i<=q;i++)
	{
		l=read();
		r=read();
		dijkstra(l);
		cout<<dis[r]+w[l]+w[r]<<"\n";
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



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
