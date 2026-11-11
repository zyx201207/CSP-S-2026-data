#include <bits/stdc++.h>
using namespace std;
const int N=3e5+7;
int h[N];
struct XB{
	int u,v,nxt;
}p[N*2];
int n,k;
int cnt=0;
void build(int u,int v)
{
	p[++cnt].nxt=h[u];
	p[cnt].u=u;
	p[cnt].v=v;
//	cout<<u<<' '<<cnt<<endl;
	h[u]=cnt;
//	cout<<h[u]<<' '<<u<<' '<<v<<' '<<cnt<<endl;
}
int depth[N];
void dfs(int u,int fa,int deep)
{
	depth[u]=deep;
	for (int i=h[u];i!=-1;i=p[i].nxt)
	{
		int v=p[i].v;
		if(v!=fa){
			dfs(v,u,deep+1);
		}
	}
}
void dfs1(int u,int fa,int deep)
{
	depth[u]=min(deep,depth[u]);
	for (int i=h[u];i!=-1;i=p[i].nxt)
	{
		int v=p[i].v;
		if(v!=fa){
			dfs(v,u,deep+1);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		int m=(n-1)/2;
		int w=m-k;
		int q=(w+1)/2;
		int z=(q+1)/2;
		cout<<z+1<<endl;
	}
	return 0;
}


