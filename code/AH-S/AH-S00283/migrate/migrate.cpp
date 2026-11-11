#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i-1]=abs(a[i]-a[i-1]);
		}
		int yy=d/a[1]+1;
		printf("%d\n",n-yy);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
