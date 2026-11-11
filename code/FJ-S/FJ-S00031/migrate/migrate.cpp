#include <bits/stdc++.h>
using namespace std;

int c,t;
long long n,d;
long long a[2000001];
int best[2000001];//从u到v的最短路径长度
long long way[2000001];//从u到v的最短路径数量 
long long ans;

bool check(int x,int y)
{
	if(abs(a[x]-a[y])<=d)return true;
	return false;
}

/*
void dfs(int f,int u,int v,int d)
{
	if(best[f][u]<d)return;//最优性剪枝
	//cout << "[info]递归" << f << " " << u << " " << v << " " << d << endl;
	if(u==v)//到达目标（d<=best[f][v]） 
	{
		if(best[f][v]>d)
		{
			best[f][v]=d;
			way[f][v]=1;
		}
		else if(best[f][v]==d)way[f][v]++;
		return;
	} 
	for(int i=u+1;i<=v;i++)
	{
		//cout << "[info]检查" << u << " " << i << " " << check(u,i) << endl;
		if(check(u,i))dfs(f,i,v,d+1);
	}
}
*/

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	cin >> c >> t;
	if(c<=10)
	{
		for(;t>0;t--)
		{
			cin >> n >> d;
			for(int i=0;i<n;i++)cin >> a[i];
			//初始化
			ans=0;
			for(int i=0;i<n;i++)
			{
				best[i]=1e9;
				way[i]=0;
			}
			
			for(int i=0;i<n-3;i++)
			{
				//初始化
				for(int j=0;j<n;j++)
				{
					best[j]=1e9;
					way[j]=0;
				}
				best[i]=0;
				way[i]=1;
				int p=0;//指针，找一个特殊点
				for(int j=i+1;j<n;j++)
				{
					if(!check(j-1,j))break;//不可能是双径岛屿对了 
					//找到一个最大的p，使得!check(p-1,j) && check(p,j)
					while(!check(p,j))p++;
					int best_d=1e9;//找到一个最优路程 
					for(int k=p;k<j;k++)
					{
						best_d=min(best[k],best_d);
					}
					for(int k=p;k<j;k++)
					{
						if(best[k]==best_d)
						{
							way[j]+=way[k];//转移 
						}
					}
					best[j]=best_d+1;
					if(way[j]==2)ans++; 
					//else if(way[j]>2)break;//不可能是双径岛屿对了
					//cout << i << " " << j << " " << best[j] << " " << way[j] << endl;
				}
			}
			cout << ans << '\n';
		}
	}
	else
	{
		//错误解法
		for(;t>0;t--)
		{
			cin >> n >> d;
			for(int i=0;i<n;i++)cin >> a[i];
			//初始化
			ans=0; 
			
			//枚举所有len>=3的点对(i,j)
			for(int i=0;i<n-3;i++)
			{
				int s=0; 
				int p=0;//指针，找一个特殊点
				for(int j=i+3;j<n;j++)
				{
					//找到一个最大的p，使得!check(p,j) && check(p+1,j)
					while(!check(p+1,j))p++;
					
					//判断是否存在一条路径可以到达
					if(!check(j-1,j))break;//不可能是双径岛屿对了 
					
					//检查是否存在特殊数对，存在1个就是，存在0个或>1个就不是 
					//(k,j)可达，(l,j)可达， (p,k)可达，(p,l)可达，(p,j)不可达，其中p<k<l<j
					//可简化为 (k,j)可达，(p,l)可达，(p,j)不可达（为了判断p=0的初始情况） 
					for(int k=p+1;k<j-1;k++)
					{
						for(int l=k+1;l<j;l++)
						{
							if(check(k,j) && check(p,l) && (!check(p,j)))s++;
						} 
					}
					
					//if(j==5)cout << "[info]" << s << " " << p << endl;
					
					if(s==1)ans++;
					else if(s>1)break;//不可能是双径岛屿对了 
				}
			} 
			cout << ans << '\n';
		} 
	}
}
