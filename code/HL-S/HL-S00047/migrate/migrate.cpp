#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long a[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			long long ch=a[2]-a[1];
			if(d<=ch){
				printf("0\n");
			}else{
				long long k=d/ch,ans=0;
				for(int i=1;i<n;i++){
					if(n-i<=k){
						break;
					}
					long long tmp=((n-i)/k-1)*(k-1)+(n-i)%k;
					ans+=tmp;
				}
				printf("%lld\n",ans);
			}
		}else{
			printf("0\n");
		}
	}
	return 0;
}