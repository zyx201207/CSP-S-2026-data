#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	scanf("%d%d" ,&c,&t);
	while(t--){
		scanf("%d%d" ,&n,&k);
		for(int i = 1;i < n;i++){
			int u,v;
			scanf("%d%d" ,&u,&v);
		}
		printf("%d\n" ,((((n >> 1) + 3) >> 1) - (k >> 1) + 1) >> 1);
	}
	return 0;
} 
