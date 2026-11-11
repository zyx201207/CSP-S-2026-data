#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,signed> P;

const signed N=505,M=20005;
const int INF=1e14+7;
//
priority_queue<P,vector<P>,greater<P> > q;

signed c,n,m,d,T;
signed rest[M];
int dis[505];
signed head[505],to[1005],nxt[1005],cnt;
signed val[1005];
signed t[505][M];
signed k[505];
bool vis[505];
vector<signed> st[M];

void add(signed u,signed v,int wal){
	cnt++;
	nxt[cnt]=head[u];
	to[cnt]=v;
	val[cnt]=wal;
	head[u]=cnt;
}
bool check(signed id,signed fi){
	signed pos=lower_bound(st[fi].begin(),st[fi].end(),id)-st[fi].begin();
	if(id==st[fi][pos]) return true;
	else return false;

//	for(signed iii:st[fi]){
//		if(iii==id){
//			return true;
//		}
//	}
//	return false;
}
int dij(signed id,signed fi){

	for(signed i=0;i<=n+1;i++){
		dis[i]=INF;
		vis[i]=false;
	}

	while(q.size()) q.pop();


	q.push(P(0,id));
	dis[id]=0;

	while(q.size()){
		signed u=q.top().second;
		if(check(u,fi)){
//			cerr<<'!'<<dis[u]<<'-'<<u<<' '<<fi<<' '<<t[1][2]<<'!';
			dis[u]+=t[u][fi];
			return dis[u];
		}
//		 cerr<<"YES";
		q.pop();
		vis[u]=true;

		for(signed i=head[u];i;i=nxt[i]){
			signed v=to[i];
			int w=val[i];

			if(vis[v]) continue;

			if(dis[v] >= dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(P(dis[v],v));
			}
		}
	}

	return INF;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>c>>n>>m>>d>>T;
	for(signed i=1;i<=m;i++){
		cin>>rest[i];
	}
	for(signed i=1;i<=n;i++){
		cin>>k[i];
		for(signed j=1,x;j<=k[i];j++){
			cin>>x;
			cin>>t[i][x];

//			cerr<<i<<' '<<x<<' '<<t[i][x]<<endl;

			st[x].push_back(i);
		}
	}
//	cerr<<t[1][0]<<endl;
	for(signed i=1;i<=m;i++){
		signed len=st[i].size();

		for(signed j=0;j<len;j++){
			for(signed k=0;k<len;k++){
				if(j==k) continue;
//				cerr<<'!'<<t[st[i][j]][i]+t[st[i][k]][i]<<endl;
				add(st[i][j],st[i][k],t[st[i][j]][i]+t[st[i][k]][i]);
			}
		}
	}
	signed x,y;
	int ans;
	while(T--){
		ans=INF;

		cin>>x>>y;
		for(signed i=0;i<st[x].size();i++){
//			cerr<<dij(st[x][i],y)<<' '<<t[st[x][i]][x]<<' ';
			ans=min(ans,dij(st[x][i],y)+t[st[x][i]][x]);
		}
//		for(int i=1;i<=n;i++){
//			cerr<<dis[i]<<' ';
//		}
		ans+=(rest[x]+rest[y]);

		cout<<ans<<endl;
	}


	return 0;
}
