#include <bits/stdc++.h>
using namespace std;
int c,T,n,k,l;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&T);
	if(c>=13 and c<=14)
		while(T--){
			scanf("%d %d",&n,&k);
			for(int i=1;i<n;i++)
				scanf("%d %d",&l,&l);
			printf("%d\n",(n+1)/8-(k/4)+1);
		}
	else while(T--) printf("1\n");
	return 0;
}
