#include<bits/stdc++.h>
using namespace std;
typedef long long ll;		
constexpr int N=2e6+5,INF=1e9;					//N is wrong
vector<int> e[N];
int n=0,ans[N]={},dis[N]={},c=0;
ll x[N]={};
queue<int> q;
ll bfs(int s)
{
	int i=0,u=0,v=0,sum=0;
	for(i=1;i<=n;i++)
		dis[i]=INF,ans[i]=0;
	q=queue<int>();
	q.push(s);
	dis[s]=0,ans[s]=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<e[u].size();i++)
		{
			v=e[u][i];
			if(dis[v]<dis[u]+1)
				continue;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1,ans[v]=ans[u];
				q.push(v);
			}	
			else 
				ans[v]+=ans[u];
		}
	}
	for(i=1;i<=n;i++)
		if(ans[i]==2)
			sum++;
	return sum;
}
void main2()
{
	int i=0,j=0,px=0,py=0,pz=0;
	ll sum=0,d=0;
	cin>>n>>d;
	for(i=1;i<=n;i++)
		cin>>x[i];
	if(c>=11&&c<=12)
	{
		if(x[2]==x[1])
			cout<<0<<'\n';
		else
		{
			px=d/(x[2]-x[1]);
			if(px<=1)
				cout<<0<<'\n';
			else
				cout<<max(0,n-2*px+1)<<'\n';
		}
		return;
	}
	if(c>=13&&c<=14)
	{
		for(i=1;x[i]+d<x[n];i++)
		{
			px=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			py=px-1;
			pz=py-1;
			if(upper_bound(x+1,x+n+1,x[py]+d)-x-1==n&&upper_bound(x+1,x+n+1,x[pz]+d)-x-1!=n)
				sum++;
		}
		cout<<sum<<'\n';
		return;
	}
	for(i=1;i<=n;i++)
		e[i].clear();
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(x[j]-x[i]<=d)
				e[i].push_back(j);
	for(i=1;i<=n;i++)
		sum+=bfs(i);
	cout<<sum<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);				//dlt
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=0,i=0;
	cin>>c>>t;
	for(i=1;i<=t;i++)
		main2();
	return 0;
}
