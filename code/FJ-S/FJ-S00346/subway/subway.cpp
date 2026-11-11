#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+10,MAXN=510;
int c,n,m,d,q;
int w[MAXM],v[MAXM][MAXN];
vector <int> be[MAXM],line[MAXN];
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))x=x*10+c-'0',c=getchar();//lguid 1411360 
	return x*f;//lguid 1411360 
}
struct node
{
	int u,li,dis;
	bool operator <(const node a)const//lguid 1411360 
	{
		return dis>a.dis;
	}
};
int dis[MAXM][MAXN];
void solve(int s,int t)
{//lguid 1411360 
	priority_queue <node> q;//lguid 1411360 
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<be[s].size();i++)//lguid 1411360 
		q.push({s,be[s][i],w[s]+v[s][be[s][i]]}),
		dis[s][be[s][i]]=w[s]+v[s][be[s][i]];
	while(!q.empty())
	{//lguid 1411360 
		node front=q.top();
		q.pop();
		int u=front.u;//lguid 1411360 
		if(dis[u][front.li]!=front.dis)continue;
		int li=front.li;
		//不换乘
		for(int i=0;i<line[li].size();i++)//lguid 1411360 
		{
			int nxt=line[li][i];//lguid 1411360 
			if(dis[nxt][li]>dis[u][li])
				dis[nxt][li]=dis[u][li],//lguid 1411360 
				q.push({nxt,li,dis[nxt][li]}); 
		}//lguid 1411360 
		//换乘//lguid 1411360 
		for(int i=0;i<be[u].size();i++)
		{
			int lii=be[u][i];
			dis[u][li]=min(dis[u][li],dis[u][lii]);//lguid 1411360 
			dis[u][lii]=min(dis[u][lii],dis[u][li]);
			if(lii==li)continue;
			for(int j=0;j<line[lii].size();j++)
			{//lguid 1411360 
				int nxt=line[lii][j];
				if(dis[nxt][lii]>dis[u][lii]+v[u][li]+v[u][lii])
					dis[nxt][lii]=dis[u][lii]+v[u][li]+v[u][lii],
					q.push({nxt,lii,dis[nxt][lii]});
			}
		}
	}
}
//神了 编译都过不了
//还找不到问题。。。
//lguid 1411360 
/*
--------------------------------
Failed to execute "E:\FJ-S00346\subway\subway.exe":
Error 0: 操作成功完成。
*/ 
signed main()//lguid 1411360 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	//地铁口到站厅
	for(int i=1;i<=m;i++)w[i]=read();
	//线路
	for(int i=1;i<=n;i++)//lguid 1411360 
	{
		int k=read();
		//地铁站数
		for(int j=1;j<=k;j++)
		{
			int id=read();//lguid 1411360 
			//编号 站厅到线路
			be[id].push_back(i); //lguid 1411360 
			v[id][i]=read();
			line[i].push_back(id);
		}
	}//lguid 1411360 
	while(q--)
	{
		int s=read(),t=read();//lguid 1411360 
		solve(s,t);
		cout<<*min_element(dis[t]+1,dis[t]+be[t].size()+1)<<'\n';
	}
	return 0;//lguid 1411360 
}
/*
世界上本没有路，走的人多了，便成了路......
OI这条路真的适合你我吗 
*/
