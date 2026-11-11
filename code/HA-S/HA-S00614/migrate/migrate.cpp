#include<queue>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int c,t;
int n,d;
int x[2000010];
bool vis[2000010];
vector<int> vec[200010];
int uu,vv,vvv;
bool dfs(int u,int v)
{
	if(u==v)
	{
		return true;
	}
	vis[u]=1;
	int flag=0;
	for(int maomao:vec[u])
	{
		
		if(!((u==uu&&maomao==vv)||(u==vv&&maomao==uu))&&!vis[maomao])
		{
//			meow "<<maomao<<endl;
			flag|=dfs(maomao,v);
		}
	}
	if(!flag)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				if(i==j)continue;
				if(abs(x[i]-x[j])<=d)
				{
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
		for(int u=1;u<=n;u++)
		{
			for(int v=u+1;v<=n;v++)
			{
				memset(vis,0,sizeof(vis));
				uu=u;
				vv=u+1;
				vvv=v;
				int a=dfs(u,v);
//				if(u==1&&v==4)
//				{
//					cout<<"maomao:\n"<<u<<" "<<v<<"\n";
//					for(int i=1;i<=n;i++)
//					{
//						cout<<vis[i]<<" "; 
//					}
//					cout<<"\n";
//				}
//				for(int i=1;i<=n;i++)
//				{
//					cout<<vis[i]<<" ";
//				}
//				cout<<endl;
				vis[u]=0;
				vis[v]=0;
//				for(int i=1;i<=n;i++)
//				{
//					cout<<vis[i]<<" ";
//				}
//				cout<<endl;
				int b=dfs(u,b);
//				for(int i=1;i<=n;i++)
//				{
//					cout<<vis[i]<<" ";
//				}
//					if(u==1&&v==4)
//				{
//					cout<<"maomao:\n"<<a<<" "<<b<<"\n";
//					for(int i=1;i<=n;i++)
//					{
//						cout<<vis[i]<<" "; 
//					}
//					cout<<"\n";
//				}
//				cout<<"maomao:"<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
				for(int i=1;i<=n;i++)
				{
					
				}
				if(a&&!b)
				{
					ans++;	
				}	
			}
		}
		cout<<ans<<'\n';	
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
