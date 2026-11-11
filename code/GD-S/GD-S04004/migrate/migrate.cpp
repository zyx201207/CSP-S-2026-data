#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool f[50005];
int dis[5005][5006][2];
int n;
long long m;
struct node{
	int x,time;
	bool operator<(const node &x)const{
		return this->time>x.time;
	}
};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k,d;
		cin>>k>>d;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=k;j++)
		{
			priority_queue<node>q;
			memset(f,0,sizeof(f));
			
			q.push({j,0});	f[j]=true;
			
			while(!q.empty())
			{
				node v=q.top();
//				cout<<v.x<<"\n";
				q.pop();
				
//				if(f[v.x]==true)
//				{
//					continue;
//				}
			
				if(dis[j][v.x][0]!=0&&dis[j][v.x][0]==v.time)
				{
					dis[j][v.x][0]=v.time;
					dis[j][v.x][1]++;
				}
				else if(dis[j][v.x][0]==0)
				{
					dis[j][v.x][0]=v.time;
					dis[j][v.x][1]++;
//					f[l]=false;
//					cout<<j<<" "<<v.x<<" "<<"\n";
				}
			
				for(int l=1;l<=k;l++)
				{
					if(abs(a[l]-a[v.x])<d)
					{
						continue;
	
					}
					if(f[l]==false)
					{
						q.push({l,v.time+1});
						f[l]=true;
					}
				}
			}
		}
		int cnt=0;
		for(int j=1;j<=k;j++)
		{
			for(int l=j;l<=k;l++)
			{
			
				if(dis[j][l][1]+dis[l][j][1]==2&&j!=l)
				{
					cnt+=1;
				}
			}
		}
		cout<<cnt/2<<"\n";

	}
	return 0;
 } 
