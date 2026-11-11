#include <iostream>
using namespace std;
int t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	scanf("%d",t);
	while(t--){
		scanf("%d",n);
		scanf("%d",d);
		for(int i=1;i<=n;i++){
			scanf("%d",a[i]);
		}
		printf("%d\n",n/2);
	}
	return 0;
}
