#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,floyd[501][501],v[500001];
struct edge{
	int to,w;
};
vector<edge> vc[500001];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(floyd,0x3f,sizeof(floyd));
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> v[i];
	for(int i=1;i<=n;i++){
		int k,u,tm;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> u >> tm;
			for(int t=0;t<vc[u].size();t++)
				floyd[i][vc[u][t].to]=floyd[vc[u][t].to][i]=tm+vc[u][t].w;
			vc[u].push_back(edge({i,tm}));
		}
	}
	for(int i=1;i<=n;i++)
		floyd[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==k)continue;
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout << floyd[i][j] << ' ';
//		cout << endl;
//	}
	for(int i=1;i<=q;i++){
		int from,to,ans=maxn;
		cin >> from >> to;
		for(int j=0;j<vc[from].size();j++)
			for(int k=0;k<vc[to].size();k++)
				ans=min(ans,floyd[vc[from][j].to][vc[to][k].to]+
					vc[from][j].w+vc[to][k].w);
		cout << ans+v[from]+v[to] << endl;
	}
}
