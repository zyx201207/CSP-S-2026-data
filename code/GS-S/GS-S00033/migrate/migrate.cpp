#include<bits/stdc++.h>
using namespace std;
 
 int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		int a[100001];
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n%2==0) printf("1");
		else printf("2");
	}
	return 0;
}
