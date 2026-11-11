#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int c,t,n,dis[N],cnt[N],ans;
long long x[N],d;
struct edge{
	int to,val;
};
vector<int> g[N]; 
queue<edge> q;

void bfs(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[s]=0;
	cnt[s]=1;
	q.push({s,0});
	while(!q.empty()){
		edge u=q.front();
		q.pop();
		for(int i=0;i<g[u.to].size();i++){
			int v=g[u.to][i];
			if(dis[v]==dis[u.to]+1){
				cnt[v]+=cnt[u.to];
			}
			if(dis[v]>dis[u.to]+1){
				dis[v]=dis[u.to]+1;
				cnt[v]=cnt[u.to];
				q.push({v,dis[v]});
			}
		}
	} 
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				ans+=(cnt[j]==2);
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}
