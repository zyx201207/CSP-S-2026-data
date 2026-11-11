#include <bits/stdc++.h>
#define ll long long
#define mkp make_pair
#define pll pair<ll,ll>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
const ll N=5e2,M=5e5,INF=3e18;
ll C,n,m,d,q;
ll W[M+5];
vector<pll> line[M+5];
ll dis[N+5][N+5];
inline rd(){
	ll s=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9'){
		s=s*10+(c^48);
		c=getchar();
	}
	return s;
}
void Floyd(){
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			dis[j][i]=dis[i][j];
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway7.in","r",stdin);
//	freopen("test.out","w",stdout);
	//fc test.out subway7.ans
	C=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(ll i=1;i<=m;i++) scanf("%lld",&W[i]);
	for(ll i=1;i<=n;i++){
		ll k=rd();
		for(ll j=1;j<=k;j++){
			ll v=rd(),t=rd();
			line[v].push_back(mkp(i,t));
//			cout<<v<<" "<<i<<' '<<t<<endl;
		}
		for(ll j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(ll i=1;i<=n;i++) dis[i][i]=0;
	for(ll i=1;i<=m;i++){
		ll sz=(ll)line[i].size()-1ll;
//		for(ll j=0;j<=sz;j++) cout<<i<<" "<<line[i][j].first<<" "<<line[i][j].second<<endl;
		for(ll j=0;j<=sz;j++){
			ll vj=line[i][j].first,wj=line[i][j].second;
			for(ll k=j+1;k<=sz;k++){
				ll vk=line[i][k].first,wk=line[i][k].second;
				dis[vj][vk]=min(wj+wk,dis[vj][vk]);
				dis[vk][vj]=dis[vj][vk];
//				cout<<vj<<" "<<vk<<" "<<wj+wk<<endl;
			}
		}
	}
//	return 0;
	Floyd();
//	for(ll i=1;i<=n;i++){
//		for(ll j=i+1;j<=n;j++) cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//	}
//	return 0;
	while(q--){
		ll x=rd(),y=rd();
		if(x==y) printf("0\n");
		ll ans=INF;
		ll szx=(ll)line[x].size()-1ll;
		ll szy=(ll)line[y].size()-1ll;
		for(ll i=0;i<=szx;i++){
			ll u=line[x][i].first,wu=line[x][i].second;
			for(ll j=0;j<=szy;j++){
				ll v=line[y][j].first,wv=line[y][j].second;
				ans=min(ans,wu+dis[u][v]+wv);
			}
		}
		printf("%lld\n",ans+W[x]+W[y]);
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
