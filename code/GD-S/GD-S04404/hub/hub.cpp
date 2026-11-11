#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int NR=1000001,R=21;
vector<int> g[NR],d[NR]; //d[i]存深度为i的 
int dep[NR],dis[NR],f[NR][R]; //dis[i]表示距离其最近的在S中的孙子的距离 
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	d[dep[x]].push_back(x);
	f[x][0]=fa;
	int i;
	for(i=1;i<R;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(i=0;i<g[x].size();i++)
		if(g[x][i]!=fa) dfs(g[x][i],x);
	return;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,i,j,p;
		cin>>n>>k;
		for(i=1;i<=n;i++)
		{
			g[i].clear();
			dis[i]=-1;
		}
		for(i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		int tmp=*max_element(dep+1,dep+n+1);
		int l=1,r=tmp-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			vector<int> s;
			i=tmp;
			for(;i>=1;i--)
				for(j=0;j<d[i].size();j++)
				{
					int x=d[i][j];
					if(dis[x]==-1)
					{
						for(p=1;p<=mid;p++)
							if(dis[f[x][0]!=-1 && p+dis[f[x][0]<=mid) break; //它可以绕过祖先去S里的元素 
							else
							{
								dis[f[x][0]=mid-p; //以免下次还要再访问
								x=f[x][0]; 
							}
						s.push_back(x); //现在x就是S的了 
						for(p=1;p<=mid;p++)
						{
							if(dis[f[x][0]]!=-1 && dis[f[x][0]]<=p) break;
							dis[f[x][0]=p; //标记这个x的祖先们 
							x=f[x][0];
						}
					}
				}
			
		}
	}
	return 0;
}
