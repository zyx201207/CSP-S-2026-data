#include<iostream>
#include<stdio.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int u,v;
		for(int i=1;i<=n-1;i++){
			scanf("%d%d",&u,&v);
		}
		n++;
		n=n/4;
		n-=(k/2);
		n=n/2;
		n++;
		printf("%d\n",n);
	}
	return 0;
}
