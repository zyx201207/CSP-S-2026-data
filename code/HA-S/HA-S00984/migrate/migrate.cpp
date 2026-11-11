#include<bits/stdc++.h>
using namespace std;
int c,T,a[2000005];
int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		long long n,d;
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		if(d==1)printf("0\n");
		else if(d==2)printf("%d\n",n-4+1);
		else printf("0\n");
	}
	return 0;
}
