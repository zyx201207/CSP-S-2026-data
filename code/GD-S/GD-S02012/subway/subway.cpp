#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,k;
//该站是否可换乘
int changeline[505]; 
//路径点
vector<int> station,change[5005];
//DFS路径点
vector<int> dfs_station,dfs_change[5005]; 
//DFS函数bool数组
vector<bool> dfs_bool_station,dfs_bool_line; 
//从站厅到站台的时间
vector<int> wt;
//地铁线路
struct stu{
	int a;
	int t;
}subwaylines[505][500005];
//起始和终点
int x,y;
//dfs函数，找路，并标记在数组，同时使用inline加速 
inline void dfs(int now,int step,int l)
{
	//到达终点，覆写路径 
	if(now==y)
	{
		//覆写路径
		for(int i=0;i<step;i++)
		{
			station[i]=dfs_station[i];
		}
		for(int line=0;line<n;line++)
		{
			for(int i=0;i<m;i++)
			{
				change[line][i]=dfs_change[line][i];
			}
		}
		
		//返回"空" 
		return ;
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			//无换乘 
			if(!dfs_bool_station[subwaylines[l][i].a]&&changeline[subwaylines[l][i].a]==0)
			{
				dfs_station[step]=subwaylines[l][i].a;
				dfs_bool_station[subwaylines[l][i].a]=1;
				dfs(subwaylines[l][i].a,step+1,l);
				dfs_bool_station[subwaylines[l][i].a]=0;
			}
			//换乘 
			else if(!dfs_bool_station[subwaylines[l][i].a]&&changeline[subwaylines[l][i].a]>=0)
			{
				for(int line=0;line<n;line++)
				{
					if(!dfs_bool_line[line])
					{
						dfs_change[line][subwaylines[line][i].a]=1;
						dfs_station[step]=subwaylines[line][i].a;
						dfs_bool_line[l]=0;
						dfs_bool_station[subwaylines[line][i].a]=1;
						dfs(subwaylines[line][i].a,step+1,line);
						dfs_bool_line[l]=1;
						dfs_bool_station[subwaylines[line][i].a]=0;
					}
				}
			}
		}
	}
	//无法达到 
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	//输入wt[i] 
	for(int i=0;i<m;i++)
	{
		cin>>wt[i];
	}
	//输入线路 
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<2*k;j++)
		{
			if(j%2==0)
			{
				cin>>subwaylines[i][j].a;
				changeline[subwaylines[i][j].a]++;
			}
			else
			{
				cin>>subwaylines[i][j-1].t;
			}
		}
	}
	//输入起始和终点，并处理 
	for(int i=0;i<q;i++)
	{
		//总时间 
		int time=0;
		cin>>x>>y;
		//经过x的线路 
		bool tx[505]; 
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<m;b++)
			{
				if(subwaylines[a][b].a==x)
				{
					tx[a]=1;
				}
			}
		}
		//将经过x的线路输入进DFS内 
		int lessest=999999;
		for(int a=0;a<n;a++)
		{
			if(tx[a])
			{
				dfs(x,0,a);
				for(int o=0;o<n;o++)
				{
					for(int j=0;j<m;j++)
					{
						if(change[o][j]!=0)
						{
							time+=subwaylines[o][j].t;
						}
					}
				}
				if(lessest>time)
				{
					time=lessest;
				}
			}
		}
		cout<<lessest<<endl;
	}
	return 0;
}
