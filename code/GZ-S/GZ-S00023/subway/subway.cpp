//GZ-S00023 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500010],k[510];
unordered_map<ll,unordered_map<ll,ll>> a,t,dist;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(ll i=1;m>=i;i++) scanf("%lld",&w[i]);
	for(ll i=1;n>=i;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;k[i]>=j;j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
		}
		for(ll x=1;k[i]>=x;x++){
			for(ll y=1;k[i]>=y;y++){
				if(dist[a[i][x]][a[i][y]]==0 && a[i][x]!=a[i][y]) dist[a[i][x]][a[i][y]]=1e18;
				dist[a[i][x]][a[i][y]]=min(t[a[i][x]][i]+t[a[i][y]][i],dist[a[i][x]][a[i][y]]);
			}
		}
	}
	for(ll k=1;m>=k;k++){
		for(ll i=1;m>=i;i++){
			for(ll j=1;m>=j;j++){
				if(dist[i][j]==0 && i!=j) dist[i][j]=1e18;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",dist[x][y]+w[x]+w[y]);
	}
	return 0;
}
