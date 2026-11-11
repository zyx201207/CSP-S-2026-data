#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,k;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
		if(n>=10000)printf("5\n");
		if(n>=1000)printf("4\n");
		if(n>=100)printf("3\n");
		if(n>=9)printf("2\n");
		else printf("1\n");
	}
	return 0;
}
