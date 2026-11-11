#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pil pair<int,ll>
#define fi first
#define sc second
const int M=5e5+7,N=507;
const ll INF=3e17;
int c,m,n,d,q;
int fa[N];
ll w[M],dis[N][N];
vector<pil>a[M];
struct Node{
	ll dist;
	int x,y;
	bool operator<(const Node other)const&{ return dist<other.dist; }
	bool operator>(const Node other)const&{ return dist>other.dist; }
};
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void build(){
	priority_queue<Node,vector<Node>,greater<Node>>q;
	memset(dis,0x3f3f,sizeof(dis));
	for(int i=1;i<=n;++i) dis[i][i]=0,fa[i]=i;
	for(int i=1;i<=m;++i) if((int)a[i].size()>=2){
		int sz=(int)a[i].size();
		for(int l=0;l<=sz-2;++l) for(int r=l+1;r<=sz-1;++r) q.push({a[i][l].sc+a[i][r].sc,a[i][l].fi,a[i][r].fi});
	}while(!q.empty()){
		Node k=q.top(); q.pop();
		int fx=find(k.x),fy=find(k.y);
		if(fx!=fy) fa[fy]=fx,dis[k.x][k.y]=dis[k.y][k.x]=k.dist;
		else if(dis[k.x][k.y]>k.dist) dis[k.x][k.y]=dis[k.y][k.x]=k.dist;
	}for(int i=1;i<=n-1;++i) for(int j=i+1;j<=n;++j) for(int k=1;k<=n;++k){
		if(k==i || k==j) continue;
		dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k; cin>>k;
		for(int j=1;j<=k;++j){
			int ai; ll ti;
			cin>>ai>>ti;
			a[ai].pb({i,ti});
		} 
	}build();
	while(q--){
		int x,y; ll ans=INF;
		cin>>x>>y;
		for(pil l:a[x]) for(pil r:a[y]) ans=min(ans,dis[l.fi][r.fi]+l.sc+r.sc);
		//cout<<x<<" "<<y<<" rd:"<<l.fi<<"&"<<r.fi<<" ctime:"<<dis[l.fi][r.fi]<<" intine:"<<l.sc+r.sc<<"\n";
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
} /*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
fc "C:\Users\Administrator\Documents\subway7.ans" "C:\Users\Administrator\Documents\subway.out"
*/
