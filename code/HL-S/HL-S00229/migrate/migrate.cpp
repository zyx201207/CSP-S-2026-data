#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define inf 1e18
using namespace std;
constexpr int N=2e6+5;
int c,t,n,d,x[N],ans;
vector<int> g[5005];
int cnt[5005],dis[5005];
void subtask1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>x[i];
	d=d/(x[2]-x[1]);
	if(d<=1)
	{
		cout<<"0\n";
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++)	if(i+2*d-1<=n)	ans++;
	cout<<ans<<"\n";
}
void dij(int id)
{
	for(int i=1;i<=n;i++)	dis[i]=inf,cnt[i]=0;
	dis[id]=0,cnt[id]=1;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({dis[id],id});
	while(q.size())
	{
		PII x=q.top();
		q.pop();
		int u=x.second,val=x.first;
		if(val!=dis[u])	continue;
		for(int v:g[u])
		{
			if(dis[v]>val+1)	dis[v]=val+1,cnt[v]=cnt[u],q.push({dis[v],v});
			else if(dis[v]==val+1)	cnt[v]+=cnt[u];
		}
	}
	for(int i=id+1;i<=n;i++)	if(cnt[i]==2)	ans++;
}
void subtask2()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)	g[i].clear();
	ans=0;
	for(int i=1;i<=n;i++)	cin>>x[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[j]-x[i]<=d)	g[i].push_back(j);
	for(int i=1;i<=n;i++)	dij(i);
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		if(c<=10)	subtask2();
		else if(c==11||c==12)	subtask1();
		else cout<<"0\n";
	}
	return 0;
}
/*
1h think+write+debug
O(n^2)+A	48pts
:(
*/
