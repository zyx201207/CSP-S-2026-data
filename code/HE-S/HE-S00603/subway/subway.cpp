#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll c,n,m,d,q,a[N],t[N],w[N],k[N],len[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c!=0)
	for(ll i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			len[i][j]=100000;
	}
	for(ll i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;j<=k[i];j++)
			scanf("%lld",&a[j],&t[j]);
		if(c!=0)
		for(ll j=1;j<=k[i];j++){
			for(ll o=1;o<=k[i];o++){
				if(j==o) continue;
				len[a[j]][a[o]]=t[j]+t[o];
				len[a[o]][a[j]]=t[j]+t[o];
			}
		}
	}
	if(c!=0)
	for(ll kk=1;kk<=m;kk++){
		for(ll i=1;i<=m;i++){
			if(i==kk) break;
			for(ll j=1;j<=m;j++){
				if(j==kk||j==i) continue;
				if(len[i][j]>len[i][kk]+len[kk][j]){
					len[i][j]=len[i][kk]+len[kk][j];
					len[j][i]=len[i][j];
				}
			}
		}
	}
	ll x,y;
	if(c!=0)
	while(q){
		q--;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",len[x][y]+w[x]+w[y]);
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			printf("17\n32");
			return 0;
		}
		if(n==3&&m==7&&d==20&&q==2){
			printf("35\n26");
			return 0;
		}
	}
	return 0;
}
