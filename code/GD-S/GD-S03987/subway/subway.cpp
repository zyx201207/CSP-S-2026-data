#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
vector<long long> v[10005];
vector<long long> v2[10005];
int c,n,m,d,p,ans,vis[N],w[N],k[N],s,e,a,t,sum;
void dfs(int point)
{
	if(point==e)
	{
		ans=max(ans,sum);
		sum=0;
		return ;
	}
//	for(int i=1;i<=n;i++)
//	{
//		if(v[i][s]==0)	continue;
//		for(int j=1;j<=k[i];j++)
//		{
//			if(v[j][])
//		}
//	}
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(v2[i][j]==point)
				{
					sum+=v2[i][j];
					if(j!=k[i]) dfs(v[i][j+1]);
					else break;
				}
			}
		}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=i;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			v[k][j].push_back(t);
			v2[k][j].push_back(a);
		}
	}
	
	while(p--)
	{
		cin>>s>>e;
		
		dfs(s);
		cout<<ans+w[s]+w[e];
	}
	
	return 0;
} 



//
//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e6+10;
//#define int long long
//struct node
//{
//	int num,time;
//}v[300][300];
//int c,n,m,d,p,ans,vis[N],w[N],k[N],s,e,a,t;
//void dfs(int point)
//{
//	if(point==e)
//	{
//		ans=max(ans,tmp);
//		return ;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=k[i];j++)
//		if(v[i][j].num==point)
//		{
//			vis[v[i][j].num]==-1;
//			
//			ans+=v[i][j].time;
//			dfs(v[i][j].num);
//			vis[v[i][j].num]==0;
//			
//		}
//	}
//}
//void bfs()
//{
//	queue<int> q;
//	q.push()
//}
//signed main()
//{
//	cin>>c>>n>>m>>d>>p;
//	for(int i=1;i<=m;i++)	cin>>w[i];
//	for(int i=i;i<=n;i++)
//	{
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++)
//		{
//			cin>>a>>t;
//			v[a].push_back();
//			v[i][j].time=t;
//		}
//	}
//	
//	while(p--)
//	{
//		cin>>s>>e;
//		ans+=w[s]+w[e];
//		dfs(s);
//	}
//	
//	return 0;
//} 
//
///*
//
//*/
