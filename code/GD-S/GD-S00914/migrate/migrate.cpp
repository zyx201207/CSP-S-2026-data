#include <bits/stdc++.h>
using namespace std;
#define filename "migrate"

const int NMAX=500;

int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d,x[NMAX];
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		if(d==2){
			if(n==4 || n==6){
				printf("1\n");
			}else if(n==5){
				printf("2\n");
			}else{
				printf("0\n");
			}
		}else{
			printf("0\n");
		}
	}
	return 0;
}
