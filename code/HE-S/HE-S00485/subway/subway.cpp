#include <bits/stdc++.h>
using namespace std;
void OI(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
void testOI(){
	freopen("subway4.in","r",stdin);
	freopen("subway4.out","w",stdout);
}
typedef long long ll;
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll w[M];
ll f[N][N];
vector<int> a[N];
struct pinfo{
	int id;
	ll t;
};
vector<pinfo> pass[M];
vector<ll> t[N];
void build(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		for(pinfo j:pass[i]){
			for(pinfo k:pass[i]){
				if(j.id==k.id)continue;
				f[j.id][k.id]=min(f[j.id][k.id],j.t+k.t);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<f[i][j]<<' ';
//		}
//		cerr<<endl;
//	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(k==j||i==j)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int x,y;
void solve(){
	ll res=1e18;
	for(pinfo i:pass[x]){
		for(pinfo j:pass[y]){
			if(j.id==i.id)res=min(res,w[x]+i.t+j.t+w[y]);
//			!!!!!!!!! may wrong!!!
			else res=min(res,w[x]+f[i.id][j.id]+i.t+j.t+w[y]);
		}
	}
	printf("%lld\n",res);
}
int main(){
	OI();
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1,k,x;i<=n;i++){
		scanf("%d",&k);
		ll y;
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			pass[x].push_back({i,y});
		}
	}
	build();
	floyd();
	for(;q--;){
		scanf("%d%d",&x,&y);
		solve();
	}
	return 0;
}

