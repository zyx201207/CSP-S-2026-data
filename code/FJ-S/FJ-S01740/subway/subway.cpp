#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
#define pb push_back
#define pil pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define gc getchar()
using namespace std;
const int N=1009,M=1000099;
int c,n,m,d,q;
ll w[M];
int k[N];
vector<pil>tun[N],tum[M];
ll jl[N][N];
void rdint(int &x){
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=gc;
	}
	x*=f;
	return ;
}
void rdll(ll &x){
	x=0;
	ll f=1ll;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1ll;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(ll)x*10+ch-'0';
		ch=gc;
	}
	x*=1ll*f;
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	FOR(i,1,m){
//		scanf("%lld",&w[i]);
		rdll(w[i]);
	}
	FOR(i,1,n){
		scanf("%d",&k[i]);
		FOR(j,1,k[i]){
			int tas;
			ll v;
//			scanf("%d%lld",&tas,&v);
			rdint(tas),rdll(v);
			tun[i].pb(mp(tas,v));
			tum[tas].pb(mp(i,v));
		}
	}
	FOR(i,1,n)
		FOR(j,1,n)
			jl[i][j]=1e17;
	FOR(i,1,n)jl[i][i]=0;
	FOR(i,1,m){
		int num=tum[i].size();
		FOR(j,0,num-1){
			FOR(k,0,num-1){
				int x=tum[i][j].fi;
				int y=tum[i][k].fi;
				jl[x][y]=min(jl[x][y],(ll)tum[i][j].se+tum[i][k].se);
			}
		}
	}
	FOR(k,1,n){
		FOR(i,1,n){
			FOR(j,1,n){
				jl[i][j]=min(jl[i][j],jl[i][k]+jl[k][j]);
			}
		}
	}
	FOR(i,1,q){
		int x,y;
		rdint(x),rdint(y);
//		scanf("%d%d",&x,&y);
		int numa=tum[x].size();
		int numb=tum[y].size();
		ll ans=1e18;
		FOR(ia,0,numa-1){
			FOR(ib,0,numb-1){
				ans=min(ans,(ll)w[x]+w[y]+tum[x][ia].se+tum[y][ib].se+jl[tum[x][ia].fi][tum[y][ib].fi]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
