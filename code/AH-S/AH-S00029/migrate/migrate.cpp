#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,m,a[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int f[n+10];
		ans=0;
		for(int i=1;i<=n;i++){
			memset(f,0x3f,sizeof f);
			for(int j=i+1;j<=n;j++){
				int minv=LONG_LONG_MAX,sum=0;
				for(int k=j-1;k>=i;k--){
					if(a[j]-a[k]>m) break;
					if(minv>f[k]) sum=0;
					sum++;
					minv=min(minv,f[k]);
				}
				f[j]=minv+1ll;
				if(sum==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
