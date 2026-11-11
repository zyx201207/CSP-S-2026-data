#include<bits/stdc++.h>
using namespace std;

int c,t;
int x[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&c,&t);
	for(int i = t;i >= 1;i--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int j = 1;j <= n;j++){
			scanf("%d",&x[j]);
		}
		printf("%lld\n",(n*(n-1))/2);
	}
	return 0;
}

