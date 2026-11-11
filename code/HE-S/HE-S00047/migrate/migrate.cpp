#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=305;
ll a[N];
struct node{
	int nxt,to;
}e[N*N];
int head[N],tot;
inline void add(int from,int to){
	tot++;
	e[tot].nxt=head[from];
	e[tot].to=to;
	head[from]=tot;
}
ll n,d;
int dis[N][N];
ll f[N][N];
void bfs(int s){
	queue<pair<int,int>> q;
	dis[s][s]=0,f[s][s]=1;
	q.push({s,0});
	while(!q.empty()){
		auto p=q.front();
		q.pop();
		int u=p.first,d=p.second;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[s][v]==n+1){
				dis[s][v]=d+1;
				f[s][v]=f[s][u];
				q.push({v,d+1});
			}else if(d+1==dis[s][v]) f[s][v]+=f[s][u];
		} 
	}
}
void solve(){
	scanf("%lld %lld",&n,&d);
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=n+1;
			f[i][j]=0;
		}
	}	
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			add(i,j);
			add(j,i);
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]==2) ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}

