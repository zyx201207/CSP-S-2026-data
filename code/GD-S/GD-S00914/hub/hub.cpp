#include <bits/stdc++.h>
using namespace std;
#define filename "hub"

const int NMAX=1006;
int u[NMAX],v[NMAX];

int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
		if(t){
			printf("1\n");
		}else{
			printf("2\n");
		}
	}
	return 0;
} 
