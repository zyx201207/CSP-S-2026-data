#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+9;
ll c,m,n,d,q;
ll W[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&W[i]);
	if(c>=9&&c<=11){
		ll f[509][509];
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++){
			ll aa,x,y,xw,yw;
			scanf("%lld",&aa);
			scanf("%lld",&x);
			scanf("%lld",&xw);
			scanf("%lld",&y);
			scanf("%lld",&yw);
			f[x][y]=min(f[x][y],xw+yw);
			f[y][x]=min(f[y][x],xw+yw);
		}
		for(int i=1;i<=m;i++)f[i][i]=0;
		
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				}
			}
		}
		while(q--){
			ll x,y;
			scanf("%lld",&x);
			scanf("%lld",&y);
			printf("%lld\n",f[x][y]+W[x]+W[y]);
		}
	}
	
	
	if(c>=7&&c<=8){
		ll f[409][409];
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++){
			ll aa,x,y,xw,yw;
			scanf("%lld",&aa);
			scanf("%lld",&x);
			scanf("%lld",&xw);
			scanf("%lld",&y);
			scanf("%lld",&yw);
			f[x][y]=min(f[x][y],xw+yw);
			f[y][x]=min(f[y][x],xw+yw);
		}
		for(int i=1;i<=m;i++)f[i][i]=0;
		
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				}
			}
		}
		while(q--){
			ll x,y;
			scanf("%lld",&x);
			scanf("%lld",&y);
			printf("%lld\n",f[x][y]+W[x]+W[y]);
		}
	}
	return 0;
} 

