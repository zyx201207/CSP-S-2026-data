#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c,t;
ll n,d,x[N];
ll y,k;
ll ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		x[n+1]=x[n+2]=x[n+3]=INF;
		k=0;y=0;
		for(int i=1;i<=n;i++){
			//printf("%lld %lld \n",i,k);
			if(k==-2) ans+=y;
			if(k==1){
				//printf("1\n");
				if(x[i-1]+d<x[i]) k=0;
				else continue;
			}
			if(x[i]+d>=x[i+1]&&x[i]+d<x[i+2]){
				//printf("0\n");
				if(k==0) y++;
				if(k==-1) k=0;
			}
			if(x[i]+d<x[i+1]){
				//printf("-1\n");
				k=-1;
				y=0;
			}
			if(x[i]+d>=x[i+1]&&x[i]+d>=x[i+2]&&x[i]+d<x[i+3]){
				//printf("-2\n");
				k=-2;
				y++;
				i=i+2;
			}
			if(x[i]+d>=x[i+3]){
				//printf("3\n");
				y=0;
				k=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
