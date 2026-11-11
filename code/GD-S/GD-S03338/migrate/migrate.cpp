#include<cstdio>
using namespace std;
long long c,t,n,d,x[2000002],ans,s[10000][10000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		if(c==11||c==12){
			long long js=x[2]-x[1],ans=0;
			if(d<=js)printf("0\n");
			else{
				if(n-d/js*2+1>0)ans=n-d/js*2+1;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
