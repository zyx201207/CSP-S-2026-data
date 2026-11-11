#include <bits/stdc++.h>
using namespace std;

#define int long  long

int c,t;
int n,d;
int a[5005];
vector<int> mapp[5005];


int dis[5005];
bool book[5005];
int cnt[505];
void dijkstra(int x)
{
	memset(dis,0x3f,sizeof(dis));
	memset(book,false,sizeof(book));
	dis[x]=0;
	
	for(int i=1;i<=n;i++)
	{
		int id=0,minn=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=n;++j)
		{
			if(minn>dis[j]&&book[j]==false)
			{
				id=j;
				minn=dis[j];
			}
		}
		book[id]=true;
		for(int j=0;j<mapp[id].size();++j)
		{
			if(dis[id]+1<dis[mapp[id][j]])
			{
				dis[mapp[id][j]]=dis[id]+1;
				cnt[id]=1;
			}
			if(dis[id]+1==dis[mapp[id][j]])
			{
				cnt[id]++;
			}
		}
	}
}

int ans=0;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t)
	{
		int minn=LLONG_MAX;
		ans=0;
		--t;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			minn=min(a[i],minn);
		}
		for(int i=1;i<=n;++i)
		{
			a[i]-=minn;
			for(int j=i+1;j<=n;++j)
			{
				a[j]-=minn;
				if(!(a[j]-a[i]<=d)) break;
				mapp[i].push_back(j);
				mapp[j].push_back(i);
			}
		}
		
		
		dijkstra(1);
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
