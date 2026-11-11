#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<long> w(m+1);
	for (int i=1;i<=m;i++)cin>>w[i];
	vector<pair<int,int>> v[500000+5];
	for (int i=1;i<=n;i++)
	{
		int k;cin>>k;
		int a,b,c,d;cin>>a>>b>>c>>d;v[a].push_back({c,b+d});v[c].push_back({a,b+d});}
	
	for (int i=1;i<=q;i++)
	{
		int q1,q2;cin>>q1>>q2;
		long long ans=w[q1]+w[q2];
		int s=q1;
		int dist[500000+5];bool vis[500000+5];
		memset(vis,0,sizeof(vis));
		memset(dist,0x3f,sizeof(dist));
		int cnt=0;
		int u=s;
		dist[s]=0;
		vector<pair<int,int>> vvv;
		while(cnt<n)
		{
			for (auto &pp:v[u])
			{int v1 = pp.first;int c=pp.second;if(vis[v1])continue;
			dist[v1]=min(dist[v1],dist[u]+c);
			vvv.push_back({dist[v1],v1});
			}
			sort(vvv.begin(),vvv.end());
			u=vvv[0].second;
			vis[u]=1;
			vvv.begin()=vvv.begin()+1;
			cnt++;
		}
		cout<<dist[q2]+ans<<'\n';
	}
	
	return 0;
}
