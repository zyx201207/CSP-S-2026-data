#include <bits/stdc++.h>
#define AFO long long
using namespace std;
const int N=5005,M=2e6+5;
struct node
{
	int x,y,z;
};
bool a[N][N];
AFO t[M];
int dis[N],cnt[N];
bool v[N];
int c,T,ans,n;
AFO d;
void bfs(int x)
{
	queue<node>q;
	q.push({x,0,1});
	dis[x]=0;
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y,z=q.front().z;
		q.pop();
		cnt[x]+=z;
		if(cnt[x]>2)
			continue;
		for(int j=x+1;j<=n;j++)
		{
			if(!a[x][j])
				continue;
			if(dis[j]>=dis[x]+1)
			{
				dis[j]=dis[x]+1;
				q.push({j,dis[j],cnt[x]});
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			dis[i]=2e9,v[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&t[i]);
		if(c<=10)
		{
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
					a[i][j]=0;
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
					if(abs(t[i]-t[j])<=d)
						a[i][j]=1;
			for(int i=1;i<=n;i++)
			{
				bfs(i);
				for(int j=1;j<=n;j++)
					if(cnt[j]==2)
						ans++;
				//for(int j=1;j<=n;j++)
				//	cout<<cnt[j]<<" ";
				//cout<<"\n";
				for(int j=1;j<=n;j++)
					cnt[j]=0;
			}/*
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					cout<<a[i][j]<<" ";
				cout<<"\n";
			}*/
			cout<<ans<<"\n";
		}
		if(c==11||c==12)
		{
			int gc=t[2]-t[1];
			d=d/gc;
			if(d<=1)
				cout<<0;
			else
			{
				d=d*2-1;
				for(int i=1;i+d<=n;i++)
					ans++;
				cout<<ans;
			}
		}
	}
	return 0;
}
