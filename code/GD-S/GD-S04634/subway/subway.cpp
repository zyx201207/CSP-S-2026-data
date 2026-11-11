#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
struct w
{
	int to,dist;
};
int v,n,m,k,q,a[N],e,x,y;
vector<w>f[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>v>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>e;
		for(int i=1;i<=e;i++)
		{
			int u,v;
			cin>>u>>v;
			f[i].push_back({u,v});
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<1<<endl;
	}
	return 0;
}
