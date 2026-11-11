#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[1000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		int k=(a[n]-a[n-1]+m-1)%m;
		if(k==1)printf("0\n");
		else printf("1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
