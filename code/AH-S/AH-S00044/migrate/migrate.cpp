#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=2e6+5;
vector<int>e[N];
long long a[M];
long long n,d;
int dis[N],cnt[N];
bool is[N][N];
int bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto&v:e[u])
		{
			if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1,cnt[v]=1;
				q.push(v);
			}
			else if(dis[u]+1==dis[v])
			{
				cnt[v]++;
				q.push(v);
			}
		}
	}
	int ret=0;
	for(int i=1;i<=n;i++)
		if(cnt[i]==2)
			++ret;
	return ret;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			long long D=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				D=a[i]-a[i-1];
			}
			if(n<=3)
			{
				cout<<0<<"\n";
				continue;
			}
			long long c=d/D;
			if(c<=1)
			{
				cout<<0<<"\n";
				continue;
			} 
			cout<<max(0ll,n-2*c+1)<<"\n";
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(auto&v:e)v.clear();
		for(int j=1,i=1;i<=n;i++)
		{
			cin>>a[i];
			while(a[i]-a[j]>d)j++;
			for(int k=j;k<i;k++)
				e[k].push_back(i);
		}
		if(n<=3)
		{
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=bfs(i);
		cout<<ans<<"\n";
	}
	return 0;
}
