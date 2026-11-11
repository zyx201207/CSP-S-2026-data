#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int test_id,n,m,d,q;
i64 w[500007];
struct node
{
	int idx,c;
	node(int id=0,int _c=0):idx(id),c(_c){}
};
vector<node> tr[500007];
i64 dis[507][507];
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
}
int u,v;
i64 ans;
signed main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>test_id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k,id,c;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>id>>c;
			tr[id].emplace_back(node(i,c));
		}
		dis[i][i] = 0;
	}
	for(int i=1;i<=m;i++)
		for(auto x:tr[i])
			for(auto y:tr[i])
				dis[x.idx][y.idx] = min(dis[x.idx][y.idx],(i64)x.c+y.c);
	floyd();
	while(q--)
	{
		cin>>u>>v;
		ans = 0x3f3f3f3f3f3f3f3f;
		for(auto x:tr[u])
			for(auto y:tr[v])
				ans = min(ans,dis[x.idx][y.idx]+x.c+y.c);
		cout<<ans+w[u]+w[v]<<'\n'; 
	}
}

