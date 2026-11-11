#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
const int N=5e5+7;
#define int long long
#define ll long long
const ll INF=100000000000000000ll;
int n,m,d,q;
struct node{
	int id,val;
};
vector<node>st[N];
ll dis[505][505],w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c;cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int siz;cin>>siz;
		rep(j,1,siz){
			int x,val;cin>>x>>val;
			st[x].emplace_back((node){i,val});
		}
	}rep(i,1,m){
		rep(j,0,(int)st[i].size()-1){
			rep(k,j+1,(int)st[i].size()-1){
				int u=st[i][j].id,v=st[i][k].id;
				ll dd=dis[u][v];
				dis[u][v]=dis[v][u]=min(dd,(ll)st[i][j].val+st[i][k].val);
			}
		}
	}rep(i,1,n)dis[i][i]=0;
	rep(k,1,n){
		rep(i,1,n){
			if(i==k||dis[i][k]>=INF)continue;
			rep(j,1,n){
				if(k!=j&&j!=i&&dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		ll ans=INF;
		for(node x:st[u]){
			for(node y:st[v]){
				int fi=x.id,se=y.id;
				ans=min(ans,dis[fi][se]+x.val+y.val);
			}
		}cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
