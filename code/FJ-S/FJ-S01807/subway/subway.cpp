#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
const int N=500+5;
const int M=5e5+5;
int c,n,m,d,Q;
int w[M];
vector<pii>p[M];
struct node {
	int pos,r;
	bool friend operator <(node a,node b) {
		return a.r>b.r;
	}
};
vector<node>v[N];
int dis[N][N];
priority_queue<node>q;
//bool vis[N];
void dij(int s) {
//	memset(vis,false,sizeof(vis));
	dis[s][s]=0;
//	vis[s]=true;
	while(!q.empty())q.pop();
	q.push(node{s,0});
	while(!q.empty()) {
		node now=q.top();
		q.pop();
		for(auto to:v[now.pos]) {
//			if(vis[to.pos])continue;
			if(dis[s][now.pos]+to.r<dis[s][to.pos]) {
				dis[s][to.pos]=dis[s][now.pos]+to.r;
				q.push(node{to.pos,dis[s][to.pos]});
//				vis[to.pos]=true;
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dis[i][j]=1e18;
		}
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			p[a].push_back(pii{i,t});
		}
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=0; j<p[i].size(); j++) {
			for(int k=j+1; k<p[i].size(); k++) {
				v[p[i][j].fir].push_back(node{p[i][k].fir,p[i][j].sec+p[i][k].sec});
				v[p[i][k].fir].push_back(node{p[i][j].fir,p[i][j].sec+p[i][k].sec});
			}
		}
	}
//	cout<<"V\n";
//	for(int i=1;i<=n;i++){
//		for(auto to:v[i]){
//			cout<<to.pos<<" "<<to.r<<endl;
//		}
//	}
//	cout<<endl;
	for(int i=1; i<=n; i++) {
		dij(i);
	}
//	cout<<"dis:"<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	while(Q--) {
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0; i<p[x].size(); i++) {
			for(int j=0; j<p[y].size(); j++) {
				int p1=p[x][i].fir,p2=p[y][j].fir;
				ans=min(ans,p[x][i].sec+p[y][j].sec+dis[p1][p2]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}