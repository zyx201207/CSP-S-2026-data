#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=5e5+10;
ll w[M],k[N],t[N][M];
vector<ll> v[M];
ll csd,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csd>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(int j=1;j<=k[i];j++){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			v[i].push_back(a);
			v[a].push_back(i);
			t[i][a]=b;
		}
	}
	while(q--){
		ll x,y,minn=0x3f3f3f3f;
		scanf("%lld%lld",&x,&y);
		if(x==y) cout<<"0\n";
		else{
			for(ll i=0;i<ll(v[x].size());i++){
				for(ll j=0;j<ll(v[y].size());j++){
					if(v[x][i]==v[y][j]) minn=min(minn,t[v[x][i]][x]+t[v[y][j]][y]+w[x]+w[y]);
				}
			}
			printf("%lld\n",minn);
		}
		
	}
	return 0;
}
