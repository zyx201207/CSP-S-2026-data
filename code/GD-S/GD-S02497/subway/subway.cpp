#include<bits/stdc++.h>
using namespace std;
#define For(i,s,e) for(int i=s;i<=e;i++)
#define dFor(i,s,e) for(int i=s;i>=e;i--)
#define int long long
const int M=5e5+10;
struct node{
	int v,nxt;
}edge[M<<1];
int head[M],tot;
void add(int u,int v){
	edge[u]=(node){v,head[u]};
	head[u]=++tot;
}
int c,n,m,d,q,w[M],k[M],vis[510],vvis[M],x,y,mn;
vector <int> t[510],a[510];
vector <pair<int,int> >to[M];
void dfs(int s,int ts){
	if(s==y){
		mn=min(mn,ts+w[y]);
		return;
	}
	for(auto wy:to[s]){
		if(vis[wy.second])continue;
		vis[wy.second]=1;
		For(i,0,k[wy.second]-1){
			int nxt=a[wy.second][i];
			if(vvis[nxt])continue;
			vvis[nxt]=1;
			dfs(nxt,t[wy.second][wy.first]+t[wy.second][i]+ts);
			vvis[nxt]=0;
		}
		vis[wy.second]=0;
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	For(i,1,m)scanf("%lld",w+i);
	int ai,ti;
	For(i,1,n){
		scanf("%lld",k+i);
		For(j,1,k[i]){
			cin>>ai>>ti;
			a[i].push_back(ai);
			t[i].push_back(ti);
			to[ai].push_back(make_pair(i,j-1));
		}	
	}
	while(q--){
		mn=1ll<<60;
		scanf("%lld%lld",&x,&y);
		vvis[x]=1;
		dfs(x,w[x]);
		vvis[x]=0;
		cout<<mn<<endl;
	}
	return 0;
}

