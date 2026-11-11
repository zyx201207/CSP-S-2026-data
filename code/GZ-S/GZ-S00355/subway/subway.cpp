//观山湖中学 梁洪锐 GZ-S00355 
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
using namespace std;
const int N=5e5+5,inf=0x3f3f3f3f,mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
void solve(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector< vector< vector<int> > >g(n+1,vector< vector<int> >(N+1));
	vector< vector<int> >t(n+1,vector<int>(N+1,0)),at(m+1);
	for(int i=1,k;i<=n;i++){
		cin>>k;
		int x=-1;
		for(int j=1,u;j<=k;j++){
			cin>>u;
			cin>>t[i][u];
			at[u].push_back(i);
			if(j==1){
				x=u;
				continue;
			}
			g[i][u].push_back(x);
			g[i][x].push_back(u);
			x=u;
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		queue<pii>q;
		q.push({l,at[l][0]});
		vector<int>vis(m+1,0);
		vector<int>dist(m+1,inf);
		int cnt=0;
		while(!q.empty()){
			int u=q.front().first,line=q.front().second;
			q.pop();
			if(vis[u]>=at[u].size()){
				continue;
			}
			vis[u]++;
			for(int i=0;i<g[line][u].size();i++){
				int v=g[line][u][i];
				if(vis[v]>=at[v].size()){
					continue;
				}
				for(int j=0;j<at[v].size();j++){
					int nline=at[v][j];
					if(line!=nline){
						dist[v]=min(dist[v],t[line][v]+t[nline][v]);
					}
					q.push({v,nline});
				}
			}
		}
		cout<<dist[r]+w[l]+w[r]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
