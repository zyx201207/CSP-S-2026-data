#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm=5e5+5,maxn=505;
ll mp[maxn][maxn],qry[100005][maxn],cah[maxn];
int w[maxm];
vector<array<int,2> > G[maxm];
vector<int> Q[maxm]; 
int main() {
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i) {
		int k; cin>>k;
		for(int j=1;j<=k;++j) {
			int a,t; cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) {
		mp[i][j]=mp[j][i]=1e18;
	}
	for(int i=1;i<=m;++i) {
		int sz=G[i].size();
		for(int j=0;j<sz;++j) {
			for(int k=j+1;k<sz;++k) {
				int dis=G[i][j][1]+G[i][k][1];
				int u=G[i][j][0],v=G[i][k][0];
//				cout<<i<<" "<<j<<" "<<dis<<'\n';
				if(dis<mp[v][u]) {
					mp[v][u]=mp[u][v]=dis;
				}
			}
		}
	}
//	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cout<<mp[i][j]<<" \n"[j==n];
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			for(int k=i+1;k<=n;++k) {
				if(mp[j][k]>mp[j][i]+mp[i][k]) {
					mp[j][k]=mp[k][j]=mp[j][i]+mp[i][k];
				}
			}
		}
	}
//	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cout<<mp[i][j]<<" \n"[j==n];
	for(int i=1;i<=q;++i) {
		int x,y; cin>>x>>y;
		Q[x].push_back(i);
		Q[y].push_back(i);
		qry[i][0]=w[x]+w[y];
	}
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) cah[j]=1e18;
		for(auto t:G[i]) {
			cah[t[0]]=min(cah[t[0]],1ll*t[1]);
			for(int k=1;k<=n;++k) cah[k]=min(cah[k],cah[t[0]]+mp[t[0]][k]);
		}
//		cout<<"--- "<<i<<'\n';
//		for(int i=1;i<=n;++i) cout<<cah[i]<<' ';
//		cout<<'\n';
		for(auto id:Q[i]) {
			for(int j=1;j<=n;++j) qry[id][j]+=cah[j];
		}
	}
	for(int i=1;i<=q;++i) {
		ll ans=*min_element(qry[i]+1,qry[i]+n+1)+qry[i][0];
		cout<<ans<<'\n';
	}
//	cerr<<1.0*clock()/CLOCKS_PER_SEC<<" "<<(&s-&t)/1048576.0<<'\n';
	return 0;
} 
