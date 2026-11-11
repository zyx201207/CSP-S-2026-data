#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int c,t;
long long n,d,a[N];
int dis[5005][5005];
int book[5005][5005];
vector <int> p[5005];
int bfs(int x)
{
	int ans=0;
	queue < pair<int,int> > q;
	q.push(make_pair(x,0));
	while(!q.empty())
	{
		pair <int,int> now=q.front();
		q.pop();
		dis[x][now.first]=now.second;
		for(int i=0;i<(int)p[now.first].size();i++)
		{
			int e=p[now.first][i];
			if(dis[x][e]>0){
				if(book[x][e]==0 && now.second+1==dis[x][e]){
					ans++;
					book[x][e]=1;
				}
				else if(book[x][e]==1 && now.second+1==dis[x][e]){
					ans--;
					book[x][e]=2;
				}
				continue;
			}
			dis[x][e]=now.second+1;
			q.push(make_pair(e,dis[x][e]));
		}
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=10)
	{
		while(t--)
		{
			memset(book,0,sizeof book);
			memset(dis,0,sizeof dis);
			for(int i=1;i<=n;i++) p[i].clear();
			scanf("%lld%lld",&n,&d);
			int last=1;
			for(int i=1;i<=n;i++)
			{
				scanf("%lld",&a[i]);
				while(a[i]-a[last]>d)
					last++;
				for(int j=last;j<i;j++)
					p[j].push_back(i);
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=bfs(i);
			cout << ans << endl;
		}
	}
	if(c>=11 && c<=12)
	{
		for(int i=1;i<=t;i++)
		{
			cin >> n >> d;
			for(int j=1;j<=n;j++)
				cin >> a[j];
		}
	}
	return 0;
}
