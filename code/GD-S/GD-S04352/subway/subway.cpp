#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,k,a1,a2,T1,T2,x,y;
ll w[500005];
ll b[1005][1005];
ll t[505][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	//if(c>6 && c<12){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j){
					b[i][j]=2147000000;
				}
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&k);
			scanf("%lld%lld%lld%lld",&a1,&T1,&a2,&T2);
			b[a1][a2]=b[a2][a1]=T1+T2;
		}
		for(int l=1;l<=m;l++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					b[i][j]=b[j][i]=min(b[i][j],b[i][l]+b[l][j]);
				}
			}
		}
		while(q--){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",w[x]+w[y]+b[x][y]);
		}
	//}
	return 0;
}
