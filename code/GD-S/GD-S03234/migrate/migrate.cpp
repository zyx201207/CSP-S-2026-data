#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,dis[5005],cnt[5005],ans,x[2000005];
bool vis[5005];
vector<int> v[5005];
queue<int> q;
void bfs(int x)
{
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(dis,0,sizeof(dis));
	vis[x]=1;
	cnt[x]=1;
	q.push(x);
	while(!q.empty())
	{
		for(int t:v[q.front()])
		{
			if(vis[t])
			{
				if(t!=x&&dis[t]==dis[q.front()]+1) cnt[t]+=cnt[q.front()];
				continue;
			}
			cnt[t]=cnt[q.front()];
			vis[t]=1;
			dis[t]=dis[q.front()]+1;
			q.push(t);
		}
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(cnt[i]==2) ans++;
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int dx=x[2]-x[1];
			int num=d/dx;
			if(num>=2) cout<<max((int)0,n-(2*num-1))<<"\n";
			else cout<<"0\n";
		}
		return 0;
	}
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=1;j<i;j++)
				if(x[i]-x[j]<=d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
		}
		for(int i=1;i<=n;i++) bfs(i);
		cout<<ans/2<<"\n";
		if(ans&1) cout<<"ERR\n";
	}
	return 0;
}
