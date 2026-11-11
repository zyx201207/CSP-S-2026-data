#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],f[510][510];
struct node{
	int a,t;
};
vector<node>g[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			g[a].push_back(node{i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)g[i].size()-1;j++)
			for(int k=j+1;k<g[i].size();k++)
				f[g[i][j].a][g[i][k].a]=f[g[i][k].a][g[i][j].a]=min(f[g[i][j].a][g[i][k].a],g[i][j].t+g[i][k].t);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(node s:g[x])
			for(node t:g[y])
				ans=min(ans,f[s.a][t.a]+s.t+t.t+w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}
