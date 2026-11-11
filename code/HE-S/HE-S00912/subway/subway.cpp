#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5,maxm=5e5+507;
int c,n,m,d,q,w[maxn];
int first[maxm],nxt[maxm<<1],to[maxm<<1],val[maxm<<1],tot;
void add(int x,int y,int z){
	nxt[++tot]=first[x];first[x]=tot;to[tot]=y;val[tot]=z;
}
struct node{
	int s;
	ll dis;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
int vis[maxn];
ll dis[501][250501];
void dijk(int s,int id){
	priority_queue<node>q;
	for(int i=1;i<=m;i++) vis[i]=0;
	for(int i=250001;i<=250001+n;i++) vis[i]=0;
	for(int i=1;i<=m;i++) dis[id][i]=1e18;
	for(int i=250001;i<=250001+n;i++) dis[id][i]=1e18;
	dis[id][s]=0;
	q.push(node{s,0});
	while(!q.empty()){
		int u=q.top().s;q.pop();
//		cout<<"###"<<u<<"###";
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=first[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[id][v]>dis[id][u]+val[i]){
				dis[id][v]=dis[id][u]+val[i];
//				cout<<dis[id][v]<<":"<<u<<"->"<<v<<" ";
				q.push(node{v,dis[id][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			add(250000+i,a,t);add(a,250000+i,t);
		}
	}
	for(int i=1;i<=n;i++) dijk(250000+i,i);
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dis[i][j]<<" ";
		}
		for(int j=250001;j<=250001+n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;ll ans=1e18;
		for(int j=1;j<=n;j++){
			ans=min(ans,dis[j][x]+dis[j][y]);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
//	system("fc subway.out subway.ans");
	return 0;
} 
