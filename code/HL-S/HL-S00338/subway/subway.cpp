#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int >
#define pil pair<int,ll >
#define pli pair<ll,int >
#define fi first
#define se second

const ll N=505,M=5e5+5,inf=4557430888798830399;

int c,n,m,d,q;
vector<pil > pos[M];
ll w[M],t[M],E[N][N],dis[N];
bool vis[N];
priority_queue<pli ,vector<pli >,greater<pli > > Q;
pii query[M];
vector<pil > e[N];

inline void dijk(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0; vis[s]=0;
	Q.push(mp(0,s));
	while(!Q.empty()){
		int p=Q.top().se; ll d=dis[p]; Q.pop();
//		cout<<p<<" "<<dis[p]<<endl;
		if(vis[p]) continue; vis[p]=1;
		for(int i=0;i<e[p].size();i++){
			int t=e[p][i].fi; ll va=e[p][i].se;
			if(d+va<dis[t]){
				dis[t]=d+va;
				Q.push(mp(dis[t],t));
			}	
		}
	}
	for(int i=1;i<=n;i++){
		E[i][s]=min(E[i][s],dis[i]);
		E[s][i]=min(E[s][i],dis[i]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a; ll t;
			scanf("%d%lld",&a,&t);
			pos[a].pb(mp(i,t));
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		query[i]=mp(x,y);
	}//in
	
	memset(E,0x3f,sizeof(E));
	for(int p=1;p<=m;p++){
		for(int i=0;i<pos[p].size();i++){
			for(int j=i+1;j<pos[p].size();j++){
				E[pos[p][i].fi][pos[p][j].fi]=min(E[pos[p][i].fi][pos[p][j].fi],pos[p][i].se+pos[p][j].se);
				E[pos[p][j].fi][pos[p][i].fi]=(E[pos[p][j].fi][pos[p][i].fi],pos[p][i].se+pos[p][j].se);
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(E[i][j]!=inf){
				e[i].pb(mp(j,E[i][j]));
				e[j].pb(mp(i,E[i][j]));
			}
	}//pre
	
		
	for(int i=1;i<=n;i++) dijk(i);
	for(int p=1;p<=q;p++){
		int x=query[p].fi,y=query[p].se;
		ll ans=inf;
		for(int i=0;i<pos[x].size();i++)
			for(int j=0;j<pos[y].size();j++){
				ans=min(ans,E[pos[x][i].fi][pos[y][j].fi]+pos[x][i].se+pos[y][j].se);
			}
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	
	return 0;
}