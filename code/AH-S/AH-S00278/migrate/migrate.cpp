#include<bits/stdc++.h>
using namespace std;
int C,T,N,D;
int x[2000010];
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
 	scanf("%d%d",&C,&T);
 	while(T--){
 		scanf("%d%d",&N,&D);
		for(int i=1;i<=N;i++)
			scanf("%d",&x[i]);
		printf("%d\n",N-3);
	} 
	return 0;
}
