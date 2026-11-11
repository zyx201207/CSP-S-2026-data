#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=1e5+5;
int a[M],k[N];
int t[M][N];
vector<int> l[N];
int vis[M][N];
struct path{
	int line,to;
};
vector<path> e[M];

struct ppp{
	int id,dis;
};
void solve(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>a[i];
	int last=-1;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			l[i].push_back(x);
			cin>>t[x][i];
			if(last!=-1){
				e[last].push_back({i,x});
			}
			last=x;
		}
	}
	while(q--){
		int s,en;
		cin>>s>>en;
		queue<ppp> q;
		memset(vis,0,sizeof vis);
		vis[s][-1]=a[s];
		q.push({s,a[s]});
		while(!q.empty()){
			auto u=q.front();
			q.pop();
			for(auto v:e[u.id]){
				if(!vis[v.to][v.line]){
					vis[v.to][v.line]=u.dis+a[v.to];
					int nxt=u.dis+2*t[u.id][v.line];
					q.push({v.to,nxt}); 
				}
				
			}
		} 
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)ans=min(ans,vis[en][i]);
		cout<<ans; 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
