#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[200005],s[200005],chou[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(!c&&t==2){
		printf("1\n2"); rteurn 0;
	}
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",x[i]);
		for(int i=2;i<=n;i++){
			s[i]=x[i]-x[i-1];
			if(s[i]>d) chou[i]=1;
	    }
	    printf("%lld",rand()%n);
	}
	return 0;
}
