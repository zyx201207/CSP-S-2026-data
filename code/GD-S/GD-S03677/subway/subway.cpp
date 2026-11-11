#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
#define ll long long
const int M=105;
vector<int>v[M]; //v[i]表示第i条线路经过的站 
vector<int> stid[M];// stid[i]表示所有经过第i个站点的线路 
int w[M];// w[i]表示第i站口到厅的时间
int ti[M][M]; //t[i][j]表示第i条线路到第j站的 时间 
bool vis[M];// vis[i]=1 表示第i个站点已被访问 
/*
换乘：台到厅（同一线路）+厅到台（不同线路）
站台属于每一个地铁站
站厅属于每一条线路
某线路经过某站 则 线路的站厅到该站站台一定需要时间 
*/
int c,n ,m, d, q;
int x, y, res;//起点终点总时间 
//当前在第st站，该站属于第line 条线路  花费时间为cnt 
void dfs(int st, int line, int cnt)
{
	if(cnt>res) return;
	if(st==y)
	{
		//cout<<"find!";
		cnt+=ti[line][st];
		res=min(res, cnt);
		return;
	}
	//cout<<st;
	int s=v[line].size();
	for(int i=0;i<s;i++)
	{
		//搜索与st是同一线路上的站 
		//cout<<"go`1\n";
		int a=v[line][i];
		if(a==st) continue;
		if(!vis[a])
		{
			//cout<< "go`2\n";
			//搜索a这个站的所有线路并出发 
			int d=stid[a].size();
			for(int j=0;j<d;j++)
			{
				int new_line=stid[a][j];
				// 如果a站继续的线路与当前线路不同 说明需要换乘 
				if(new_line!=line)
				{
					cnt+=ti[line][a]+ti[new_line][a];
				}
				vis[a]=1;
				dfs(a, new_line, cnt);
				vis[a]=0;
			}
		}
	}
 } 
 void init()
 {
 	res=1e8;
 	
 }
 
 int main()
 {
 	freopen("subway.out", "r", stdin);
 	freopen("subway.in", "w",stdout); 
 	cin>> c>>n>>m>>d>>q;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>w[i];//输入每个站台到站口时间 
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	int x;
	 	cin>>x; //第i条线路共经过x个站
	 	bool f=1;
		 for(int j=1;j<=x;j++)
		 {
		 	int a, t;
		 	cin>>a>>t;
		 	stid[a].push_back(i);//表示第a站被第i条线路经过
			ti[i][a]=t; //表示第i条线路站厅到第a站站台所需时间
			v[i].push_back(a);
		  } 
	 }
	while(q--)
	{
		
		cin>>x>>y;
		init();
		int s=stid[x].size();
		int rres=1e8;
		for(int i=0;i<s;i++)
		{
			int line=stid[x][i];
			dfs(x, line, 0);
			res+=w[x]+w[y]+ti[line][x];
			rres=min(rres, res);
		}
		cout<<rres<<endl;
	}
 	return 0;
 }
