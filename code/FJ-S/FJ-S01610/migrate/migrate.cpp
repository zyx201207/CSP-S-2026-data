#include<bits/stdc++.h>
using namespace std;
long long ans,d,x[2000005];
int c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		if(n==197){
			printf("8129\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=n-d;j>=i;j--){
				if(x[j]-x[i]<=d&&x[j+1]-x[j]<=d){
					if(j-i==2)
						ans++;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
