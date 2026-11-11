#include<bits/stdc++.h>
#define p pair<long long,int>
using namespace std;
const int maxm=5e5+5,maxn=505;
const long long inf=LONG_LONG_MAX;
int c,n,m,d,q;
long long w[maxm];
//the time from 'zhan' to 'ting' or from 'ting' to 'zhan'
vector<pair<int,long long>> g[maxm];
//next station & the time from 'ting' to 'tai' add from 'tai' to 'ting'
long long t[maxm];
void dijsktra(int s)
{
	priority_queue<p,vector<p>,greater<p>> q;
	//how long it needs & now station
	vector<bool> flag(m+5,false);
	q.push({0,s});
	fill(t+1,t+1+m,inf);
	flag[s]=1;
	while(q.size())
	{
		auto nod=q.top();
		q.pop();
		int u=nod.second;
		long long now=nod.first;
		for(auto tmp:g[u])
		{
			int v=tmp.first;
			long long cost=now+tmp.second;
			t[v]=min(cost,t[v]);
			if(flag[v])
				continue;
			flag[v]=1;
			q.push({t[v],v});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a[k],t1[k];
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t1[j];
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				g[a[j]].push_back({a[l],t1[j]+t1[l]});
				g[a[l]].push_back({a[j],t1[j]+t1[l]});
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijsktra(x);
		cout<<(t[y]+w[x]+w[y])<<endl;
	}
	return 0;
}
