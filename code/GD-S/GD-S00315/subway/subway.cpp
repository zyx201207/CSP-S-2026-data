#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e5+5;
struct node{
	int val,dis;
}e[N];
int csd,n,m,d,q,z[N],w[N],t[N][25];
int dis[N],head[N],nxt[N],to[N],cnt=0;
bool vis[N],a[N][25];
void add(int x,int y,int z){
	cnt++;
	to[cnt]=z;
	head[cnt]=x;
	nxt[cnt]=head[y];
}
void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<node> q;
	q.push((node){s,0});
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		int x=tmp.dis;
		for(int i=head[x];i;i=nxt[x]){
			int y=nxt[i];
			if(dis[y]>dis[x]+to[i]){
				q.push((node){dis[y],y});
				vis[i]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>csd>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int _=1;_<=n;_++){
		cin>>z[_];
		for(int i=1,x,y;i<=z[_];i++){
			cin>>x>>y;
			a[i][x]=1;
			t[i][x]=y;
		}
	}
	for(int _=1,x,y;_<=q;_++){
		int ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		for(int i=1;i<=n;i++){
			if(a[i][x]) ans+=t[i][x];
			if(a[i][y]) ans+=t[i][y];
		}
		for(int i=1;i<=n;i++){
			if(a[i][x]){
				for(int j=1;j<=z[i];j++){
					if(a[j][x]&&j!=i){
						ans+=t[j][x];
					}
				}
			}
			if(a[i][y]){
				for(int j=1;j<=z[i];j++){
					if(a[i][j]&&j!=i){
						ans+=t[j][y];
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
