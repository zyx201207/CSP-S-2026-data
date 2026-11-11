#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const ll MAXN=105,MAXM=405,MAXD=25;
ll c,n,m,d,q,w[500005],t[MAXN][MAXM],k[MAXN],p[MAXM][MAXD],cnt[MAXN],fl[MAXM][MAXM];//p[i][j]:第i站的第j条地铁
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1; i<=m; i++) {
		w[i]=read();
	}
	if(c<=8) {
		memset(t,0x3f,sizeof(t));
		for(ll i=1; i<=n; i++) {
			k[i]=read();
			for(ll j=1; j<=k[i]; j++) {
				ll a=read();
				t[i][a]=read();
			}
		}
		memset(fl,0x3f,sizeof(fl));
		for(ll k=1; k<=n; k++) {
			for(ll i=1; i<=m; i++) {
				for(ll j=1; j<=m; j++) {
					if(i!=j) {
						fl[i][j]=min(fl[i][j],t[k][i]+t[k][j]);
						fl[j][i]=min(fl[j][i],t[k][i]+t[k][j]);
					}
				}
			}
		}
		for(ll k=1; k<=m; k++) {
			for(ll i=1; i<=m; i++) {
				for(ll j=1; j<=m; j++) {
					if(i!=j)
						fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
				}
			}
		}
		for(ll i=1; i<=q; i++) {
			ll x=read(),y=read();
			if(x==y)printf("0\n");
			else {
				printf("%lld\n",fl[x][y]+w[x]+w[y]);
			}
		}
	}
//	else if(c==20||c==21){
//		ll b[500005],k=read(),cnt,f[500005],hc=0,v1,v2;
//		memset(b,0,sizeof(b));
//		memset(f,0,sizeof(f));
//		for(ll i=1;i<=k;i++){
//			ll a;
//			a=read();
//			b[a]=read();
//			f[a]=1;
//			w[a]+=b[a];
//		}
//		k=read();
//		for(ll i=1;i<=k;i++){
//			ll a=read();
//			if(t[a]!=0){
//				hc=b[a];
//				v1=b[a];
//				w[a]-=b[a];
//				b[a]=read();
//				v2=b[a];
//				hc+=b[a];
//				cnt=a;
//				continue;
//			}
//			b[a]=read();
//			f[a]=2;
//			w[a]+=b[a];
//		}
//		for(ll i=1;i<=q;i++){
//			ll x=read(),y=read();
//			if(f[x]==f[y]){
//				printf("%lld\n",w[x]+w[y]);
//			}else if(x==cnt){
//				if(f[y]==1){
//					printf("%lld\n",w[x]+v1+w[y]);
//				}else{
//					printf("%lld\n",w[x]+v2+w[y]);
//				}
//			}else if(y==cnt){
//				if(f[x]==1){
//					printf("%lld\n",w[y]+v1+w[x]);
//				}else{
//					printf("%lld\n",w[y]+v2+w[x]);
//				}				
//			}else{
//				printf("%lld\n",w[x]+hc+w[y]);
//			}
//		}
//	}
	return 0;
}
