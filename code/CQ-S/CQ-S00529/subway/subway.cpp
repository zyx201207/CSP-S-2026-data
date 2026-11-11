#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
#define M 500005
ll c,n,m,d,q;
ll WW[M];
ll mp[N][N];
struct edge{
	ll xian,val;
};
vector<edge>G[M];
vector<edge>Us[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	clock_t t0=clock();
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>WW[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		while(k--){
			ll A,T;
			cin>>A>>T;
			Us[i].push_back((edge){A,T});
			G[A].push_back((edge){i,T});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			mp[i][j]=2e18;
		}
		mp[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		for(edge r:Us[i]){
			for(edge pt:G[r.xian]){
				mp[i][pt.xian]=mp[pt.xian][i]=min(mp[i][pt.xian],r.val+pt.val);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		ll S,T;
		cin>>S>>T;
		ll answer=2e18;
		for(edge A:G[S]){
			for(edge B:G[T]){
				answer=min(answer,A.val+B.val+mp[A.xian][B.xian]+WW[S]+WW[T]);
			}
		}
		cout<<answer<<endl;
	}
	fprintf(stderr,"time=%.3fs\n",(double)(clock()-t0)/CLOCKS_PER_SEC);
	return 0; 
}
