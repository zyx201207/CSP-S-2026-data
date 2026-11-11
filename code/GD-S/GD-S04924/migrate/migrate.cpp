#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c,t,n,d,x[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		if(n < 4){
			printf("0\n");
			continue;
		}printf("%d\n",n - 3);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
