 #include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5010;
const ll INF=4e18;
vector<int>G[N];
ll c,t,dist[N][N],a[N],cnt[N][N];
bool vis[N];
int n;
struct node{
	int u;
	ll val;
	bool operator<(const node &b)const{
	return u>b.u;
	}
};
void dij(int cur){
	priority_queue<node> q;
	for(int i=1;i<=n;i++)vis[i]=0;
	dist[cur][cur]=0;
	q.push({cur,0});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:G[u]){
			if(dist[cur][v]>dist[cur][u]+1){
				cnt[cur][v]=1;
				dist[cur][v]=dist[cur][u]+1;
				q.push({v,dist[cur][v]});
			}
			else if(dist[cur][v]==dist[cur][u]+1){
				cnt[cur][v]++;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    ll d,ans=0;
	    cin>>n>>d;
	    for(int i=1;i<=n;i++){
	    	G[i].clear();
	    	for(int j=1;j<=n;j++){
	    		if(i==j)continue;
	    		dist[i][j]=INF;
			}
		}
		int l=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			while(l<i&&((abs(a[i]-a[l]))>d))l++;
			for(int j=l;j<i;j++){
				G[j].push_back(i);
				G[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)dij(i);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
