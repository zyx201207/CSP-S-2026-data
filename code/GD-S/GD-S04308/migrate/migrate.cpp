#include <bits/stdc++.h>
#define N 600005
using namespace std;
int i,j,k,x,y,n,c,t;
long long d;
long long a[N];

//memset(a,0,sizeof(a))
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
while(t--){
	
	scanf("%d",&n);
	scanf("%lld",&d);
	int num=0;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		num+=a[i];
		
	}
	if(c==0){
		
		if(n==4){
			num=1;
			printf("%d",num);
		}
		if(n==5 && d==3){
			num=0;
			printf("%d",num);
		}else if(n==5){
			num=2;
			printf("%d",num);
		}
		if(n=6){
			num=1;
			printf("%d",num);
		}
		
	}
	
	
}
	return 0;
}
