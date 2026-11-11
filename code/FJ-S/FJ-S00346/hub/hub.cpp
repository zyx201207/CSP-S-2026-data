#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
vector <int> g[MAXN];
int dis[MAXN],k;//lguid 1411360
vector <int> d; 
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+1;
	for(auto v:g[u])
		if(v!=fa)
			dfs(v,u);
}
bool flag;
void getd(int u,int fa,int max2)
{
	if(flag)return ;
	for(auto v:g[u])
		if(v!=fa)//lguid 1411360
		{
			d.push_back(v);
			if(v==max2)
			{//lguid 1411360
				flag=1;
				return ;
			}
			getd(v,u,max2);//lguid 1411360
			d.pop_back();
		}
}
void check(vector <int> &c)
{
	//haha//lguid 1411360
	//18点15分 //lguid 1411360
	// /hub 
	//no time for me
}
void choose(int u,int cnt,vector <int> &c)
{//lguid 1411360
	if(cnt==k)
	{
		check(c);//lguid 1411360
		return ;
	}//lguid 1411360 //lguid 1411360
	for(int i=u+1;i<d.size();i++)
		c.push_back(d[i]),choose(i,cnt+1,c),c.pop_back();//lguid 1411360
}//lguid 1411360
void work()
{
	int n,k;
	cin>>n>>k;//lguid 1411360
	for(int i=1;i<=n;i++)g[i].clear();//lguid 1411360
	for(int i=1;i<n;i++)//lguid 1411360
	{
		int u,v;//lguid 1411360
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);//lguid 1411360
	}//lguid 1411360
	memset(dis,0,sizeof(dis));
	dfs(1,1);//lguid 1411360
	int max1=max_element(dis+1,dis+1+n)-dis;
	memset(dis,0,sizeof(dis));
	dfs(max1,max1);//lguid 1411360//lguid 1411360
	int max2=max_element(dis+1,dis+1+n)-dis;
	d.push_back(max1);//lguid 1411360
	getd(max1,max1,max2);//lguid 1411360
	vector <int> c;
	choose(-1,0,c);//lguid 1411360//lguid 1411360
}
int main()
{
	freopen("hub.in","r",stdin);//lguid 1411360
	freopen("hub.out","w",stdout);
	int t;//lguid 1411360
	cin>>t;
	while(t--)work();
}
/*
世界上本没有路，走的人多了，便成了路......
OI这条路真的适合你我吗 
*/
