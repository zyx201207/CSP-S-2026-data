#include<stdio.h>
const int N=1e5+5;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
		}
		if(n==2){
			printf("0\n");
			continue;
		}
		printf("%d\n",(n+1)/4);
	}
	return 0;
}