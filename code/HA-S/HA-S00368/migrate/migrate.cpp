#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,x[N],d;
vector<int> l[5010];
int dis[5010],vis[5010],num[5010];
queue<int>q;
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	num[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto y:l[x])
		{
			if(dis[y]>dis[x]+1) 
			{
				dis[y]=dis[x]+1;
				num[y]=num[x];
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				}
			}
			else if(dis[y]==dis[x]+1)
				num[y]+=num[x];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			l[i].clear();
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d) 
				{
					l[i].push_back(j);
//					l[j].push_back(i);
				}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<i<<endl;
//			for(auto j:l[i])
//				cout<<j<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++) 
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
				if(num[j]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
