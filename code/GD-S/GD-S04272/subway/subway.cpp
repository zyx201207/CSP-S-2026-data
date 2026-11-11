#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long c,n,m,d,q;
const long long M=5e5+5;
struct Z{
	long long id,val;
};
struct cmp
{
	bool operator()(const Z& a,const Z& b)
	{
		return a.val<b.val;
	}
};
vector<long long> w(M,0);
vector<vector<Z>> a;
vector<vector<long long>> dis;
priority_queue<Z,vector<Z>,cmp> pq;
void Dijkstra(long long s)
{
	while(!pq.empty()) pq.pop();
	dis[s][s]=0;
	pq.push({s,0});
	while(!pq.empty())
	{
		Z f=pq.top();
		pq.pop();
		if(f.val>dis[s][f.id]) continue;
		for(Z e:a[f.id]) if(dis[s][e.id]>dis[s][f.id]+e.val)
		{
			dis[s][e.id]=dis[s][f.id]+e.val;
			pq.push({e.id,dis[s][e.id]});
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	if(c==20||c==21)
	{
		if(n==1)
		{
			long long k;
			cin>>k;
			for(long long i=1;i<=k;i++)
			{
				long long num,x;
				cin>>num>>x;
				w[num]+=x;
			}
			for(long long i=1;i<=q;i++)
			{
				long long u,v;
				cin>>u>>v;
				cout<<w[u]+w[v]<<"\n";
			}
			return 0;
		}
	}
	dis=vector<vector<long long>>(m+5,vector<long long>(m+5,0x3f3f3f3f)),a=vector<vector<Z>>(m+5,vector<Z>());
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		vector<long long> num(k+5,0),dist(k+5,0);
		for(long long j=1;j<=k;j++) cin>>num[j]>>dist[j];
		for(long long j=1;j<=k;j++) for(long long h=j+1;h<=k;h++)
		{
			a[num[j]].push_back({num[h],dist[j]+dist[h]});
			a[num[h]].push_back({num[j],dist[j]+dist[h]});
		}
	}
	//for(long long i=1;i<=m;i++)
	//{
	//	cout<<i<<":\n";
	//	for(Z e:a[i]) cout<<e.id<<" "<<e.val<<"\n"; 
	//}
	for(long long i=1;i<=m;i++) Dijkstra(i);
	for(long long i=1;i<=q;i++)
	{
		long long u,v;
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
