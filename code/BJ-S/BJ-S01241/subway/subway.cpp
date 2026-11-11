#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[505],w[500005],w2[500005],dist[2000][2000],res;
unordered_map<long long,long long> dict,dict2;
struct node
{
	long long v,w;
};
vector<node> G[500005];
vector<node> tong[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i = 1;i <= m;i++)
	{
		cin>>w[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		long long k;
		cin>>k;
		for(long long j = 1;j <= k;j++)
		{
			long long aa,t;
			cin>>aa>>t;
			tong[aa].push_back({i,t});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	long long cnt = 0;
	for(long long i = 1;i <= m;i++)
	{
		if(tong[i].size() == 1)
		{
			dict[i] = tong[i][0].v;
			w2[i] = tong[i][0].w;
		}
		else
		{
			++cnt;
			dict2[i] = n+cnt;
			for(long long j = 0;j < tong[i].size();j++)
			{
				G[n+cnt].push_back(tong[i][j]);
				dist[n+cnt][tong[i][j].v] = min(dist[n+cnt][tong[i][j].v],tong[i][j].w);
				G[tong[i][j].v].push_back({n+cnt,tong[i][j].w});
				dist[tong[i][j].v][n+cnt] = min(dist[tong[i][j].v][n+cnt],tong[i][j].w);
			}
		}
	}
	for(long long i = 1;i <= n+cnt;i++)
	{
		dist[i][i] = 0;
	}
	for(long long k = 1;k <= n+cnt;k++)
	{
		for(long long i = 1;i <= n+cnt;i++)
		{
			for(long long j = 1;j <= n+cnt;j++)
			{
				dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	/*for(auto it : dict)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	for(long long i = 1;i <= n+cnt;i++)
	{
		cout<<i<<":"<<endl;
		for(long long j = 0;j < G[i].size();j++)
		{
			cout<<G[i][j].v<<" "<<G[i][j].w<<endl;
		}
	}*/
	//cout<<"looking for:"<<cnt<<endl;
	for(long long i = 1;i <= q;i++)
	{
		long long x,y;
		cin>>x>>y;
		res = w[x]+w[y];
		if(dict[x]) res += w2[x];
		if(dict[y]) res += w2[y];
		res += (dict[x] == dict[y] && dict[x] != 0) ? 0 : dist[dict[x] == 0 ? dict2[x] : dict[x]][dict[y] == 0 ? dict2[y] : dict[y]];
		cout<<res<<endl;
	}
}
