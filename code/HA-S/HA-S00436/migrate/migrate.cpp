#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5;
const int M=5e3+5;
ll c,T,n,d,ans;
ll a[N],w[M][M],dp[M][M],o[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	if (c<=10){
		while (T--){
			scanf("%lld%lld",&n,&d);
			for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
			ans=0;
			memset(o,0,sizeof o);
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++) w[i][j]=1e15;
			}
			for (ll i=1;i<=n;i++){
				w[i][i]=0;
				ll cnt=1;
				for (ll j=i+1,b=a[i],lj=i+1;j<=n;j++){
					if (a[j]<=b+d) w[i][j]=cnt;
					else {
						if (cnt==1) o[i]=j;
						if (lj==j) break;
						else b=a[j-1],w[i][j]=cnt+1,cnt++,lj=j;
					}
				}
				if (!o[i]) o[i]=n+1;
			}
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (i==j) dp[i][j]=1;
					else dp[i][j]=0;
				}
			} 
//			for (int i=1;i<=n;i++) printf("%lld ",o[i]);
//			puts("");
			for (int k=1;k<n;k++){
				for (int i=1;i+k<=n;i++){
					if (i+k<o[i]){
						dp[i][i+k]=1;
						continue;
					} 
					for (int j=i+1;j<min((ll)i+k,o[i]);j++){
						dp[i][i+k]+=(dp[i][j]*dp[j][i+k])*(w[i][j]+w[j][i+k]==w[i][i+k]);
					}
				}
			}
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					if (dp[i][j]==2) ans++;
				}
			}
//			for (int i=1;i<=n;i++){
//				for (int j=i;j<=n;j++){
//					printf("%lld ",w[i][j]);
//				}
//				puts("");
//			}
//			for (int i=1;i<=n;i++){
//				for (int j=i;j<=n;j++){
//					printf("%lld ",dp[i][j]);
//				}
//				puts("");
//			}
			printf("%lld\n",ans);
		}
	}
	if (c==11||c==12){
		while (T--){
			scanf("%lld%lld",&n,&d);
			for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
			ans=0;
			ll len=a[2]-a[1];
			if (d<=len){
				puts("0");
				continue;
			} 
			d=d/len;
			if (d<2) {
				puts("0");
				continue;
			}
			for (int i=1;i<=n;i++){
				if (i+2*d-1<=n) ans++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
