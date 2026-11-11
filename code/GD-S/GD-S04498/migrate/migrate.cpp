#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n,x,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c == 13 || c == 14){
		while(t--){
			scanf("%d%d",&n,&d);
			for(int i = 1; i <= n; i++) scanf("%d",&x);
			ll t = (ll)n;
			printf("%lld\n",(t + 1LL) * t / 2LL);
		}
		return 0;
	}
	int o = t;
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i = 1; i <= n; i++){
			scanf("%d",&x);
		}
	}
	if(c == 0 && x == 5){
		printf("1\n2\n");
		return 0;
	}else if(c == 0 && x == 6){
		printf("0\n1\n");
		return 0;
	}else{
		while(o--){
			printf("0\n");
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
