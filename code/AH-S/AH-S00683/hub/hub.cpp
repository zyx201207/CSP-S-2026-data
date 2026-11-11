#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cs,t,n,k,u,v;
	scanf("%d%d",&cs,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
		}
		if(n==k){
			printf("0\n");
			continue;
		}
		int gg=(n-1)/2+2;
		if(k+1<=gg){
			int kk=gg-k;
			int u=(kk-1)/4+1;
			printf("%d\n",u);
		}else{
			printf("1\n");
		}
	}
	return 0;
}
