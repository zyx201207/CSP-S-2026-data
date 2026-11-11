#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long x[200005],d;
vector<int> g[200005];
int cnt[200005];
int dis[5005];
queue<pair<long long,int>> q;
void bfs(int fr,int to){
	fill(dis,dis+1+n,2e18);
	q=queue<pair<long long,int>>();
	dis[fr]=0;
	q.push({0,fr});
	while(!q.empty()){
		int u=q.front().second;
		long long weight=q.front().first;
		q.pop();/*
		if(to==u){
			dis[u]=min(dis[u],weight);
			while(!q.empty()){
				u=q.front().second;
				weight=q.front().first;
				q.pop();
				if(u==to&&weight==dis[u]) cnt[to]++;
			}
			return ;
		}*/
	//	if(to==u) return ;
		if(dis[u]!=weight) continue;
		for(int v:g[u]){
			if(weight+1<dis[v]){
				dis[v]=weight+1;
				q.push({dis[v],v});
			}
		}
	}
}
void bf(int fr,int to){
	//cnt[to]=1;
	long long rd=dis[to];
	fill(dis,dis+1+n,2e18);
	fill(cnt,cnt+1+n,1);
	q=queue<pair<long long,int>>();
	dis[fr]=0;
	q.push({0,fr});
	while(!q.empty()){
		int u=q.front().second;
		long long weight=q.front().first;
		q.pop();
		if(cnt[u]>n) return;
		if(weight==dis[u]) cnt[u]++;
		
		//if(dis[u]!=weight) continue;
		for(int v:g[u]){
			if(weight+1<=dis[v]){
				if(weight+1<dis[v]) cnt[v]=1;
				dis[v]=weight+1;
				q.push({dis[v],v});
			}
			//if(to==v&&rd==weight+1) cnt[to]=(cnt[to]+1)*cnt[u];
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
long long ans=0;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			int to=lower_bound(x+1,x+1+n,x[i]+d)-x;
			if(to>n) continue;
			while(x[to]>x[i]+d) to--;
			//cout<<i<<' '<<to<<'\n';
			for(int j=i+1;j<=to;j++){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) continue;//Ö±´ï×î¶Ì 
				bfs(i,j);
				bf(i,j);
				if(cnt[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
