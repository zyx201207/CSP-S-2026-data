#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=2*1e9+9;
ll c,n,m,d,q,k,xx,yy;
ll b[1010],a[1010][1010],t[1010],x[1010];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			if(i==j) continue;
			a[i][j]=P;
		}
	}
	for(ll i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++){
			scanf("%lld%lld",&x[j],&t[j]);
		}
		for(ll j=1;j<=k;j++){
			for(ll z=1;z<=k;z++){
				a[x[j]][x[z]]=min(a[x[j]][x[z]],t[j]+t[z]);
			}
		}
	}
	if(n!=1){
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=m;j++){
				for(ll k=1;k<=m;k++){
					if(a[i][j]>a[i][k]+a[j][k]) a[i][j]=a[i][k]+a[j][k];
				}
			}
		}
	}
	
	while(q--){
		scanf("%lld%lld",&xx,&yy);
		printf("%lld\n",b[xx]+b[yy]+a[xx][yy]);
	}
	return 0;
}
