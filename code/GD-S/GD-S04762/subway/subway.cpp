#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=509,inf=1e16,M=5e5+9;
int dis[N][N],n,m,c,d,q,w[M];
struct Node{
	int a,t;
};
struct node{
	int pos,val;
};
vector<Node>v[M];
int sz[M];
vector<node>fr[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x,v[i].resize(x+1),sz[i]=x;
		for(int j=1;j<=sz[i];j++) cin>>v[i][j].a>>v[i][j].t,fr[v[i][j].a].pb((node){i,v[i][j].t});
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(auto p:fr[i]) for(auto q:fr[i]) dis[p.pos][q.pos]=min(dis[p.pos][q.pos],p.val+q.val),dis[q.pos][p.pos]=min(dis[q.pos][p.pos],p.val+q.val);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		int ans=inf;
		for(auto p:fr[x]) for(auto q:fr[y]) ans=min(ans,dis[p.pos][q.pos]+p.val+q.val);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
