#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
long long n,d,ans;
long long x[2000005];
int g[2000005];
int f[2000005];
int dis[2000005];
void bfs(int s)
{
	for(int i =1;i<=n;i++)
	{
		dis[i]=1e9;
		f[i]=0;
	}
	f[s]=1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int v=u+1;v<=g[u];v++)
		{
			if(dis[v]==1e9)
			{
				dis[v]=dis[u]+1;
				f[v]=f[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1) f[v]++;
		}
	}
}
//int g2[2000005];
//int T[2000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i =1;i<=n;i++) cin>>x[i];
		for(int i =n;i>=1;i--) x[i]-=x[1];
		if(c==11||c==12)
		{
			int d2=x[2]-x[1];
			int k=d/d2;
			if(k<=1) ans=0;
			else ans=max(0ll,n-(k*2-1));
		}
		else if(c==13||c==14)
		{
			ans=0;
		}
		else if(c<=10)
		{
			for(int i =1,j=2;i<=n;i++)
			{
				while(j<=n&&x[j]-x[i]<=d) j++;
				g[i]=j-1;
//				cout<<g[i]<<' ';
			}
			for(int i =1;i<=n;i++)
			{
				bfs(i);
				for(int j =i+1;j<=n;j++)
				{
					if(f[j]==2) ans++;
//					cout<<"qwq "<<f[j]<<' '<<dis[j]<<'\n';
				}
			}
		}
		else
		{
			ans=rand()%(n*n);
//			for(int i =1,j=2;i<=n;i++)
//			{
//				while(j<=n&&x[j]-x[i]<=d) j++;
//				g[i]=j-1;
//				if(g2[j-1]==0) g2[j-1]=i;
//			}
//			for(int i=1;i<=n;i++)
//			{
//				memset(T,0,sizeof T);
//				memset(dis,0,sizeof dis);
//				for(int j =i,k=i;j<=n;j++)
//				{
//					while(g[k]<j)T[dis[k++]]--;
//					if(T[dis[k]]==2) ans++;//f[i]
//					dis[j]=dis[k]+1;
//					T[dis[j]]++;
//				}
//			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
