#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10,M=2e6+10;
typedef long long ll;
int n;
ll a[N],c,d,t;
ll cnt[N][N],dis[N][N];
bool vis[N];
int fst[M],nxt[M],to[M],tot;
void add(int u,int v){
	nxt[++tot]=fst[u];
	to[tot]=v;
	fst[u]=tot;
}
struct node2{
	ll u,dis;
	friend bool operator<(node2 a,node2 b){
		return a.dis>b.dis;
	}
};
void dijkstra(int x){
	priority_queue<node2> q;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[x][i]=1e18;
	}
	q.push({x,0});
	dis[x][x]=0;
	cnt[x][x]=1;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=fst[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[x][u]+1<dis[x][v]){
				dis[x][v]=dis[x][u]+1;
				cnt[x][v]=cnt[x][u];
				q.push({v,dis[x][v]});
			} 
			else if(dis[x][u]+1==dis[x][v]){
				cnt[x][v]+=cnt[x][u];
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(fst,0,sizeof fst);
		tot=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			ll j=i-1,k=i+1;
			while(j && a[i]-a[j]<=d){
				add(i,j);
				j--;
			}
			while(k<=n && a[k]-a[i]<=d){
				add(i,k);
				k++;
			}
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
