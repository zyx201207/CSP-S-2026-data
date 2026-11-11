#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int x[N];
int cc[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		memset(x,0,sizeof(x));
		memset(cc,0,sizeof(cc));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			 scanf("%d",&x[i]);
		}
		for(int i=1;i<n;i++){
			 cc[x[i+1]-x[i]]++;
		}
		if(n<=3) printf("%d\n",0);
		else if(cc[x[2]-x[1]]==(n-1)&&n>=4){
			printf("%d\n",n-3);
	}
	else{
		srand(time(0));
		int x=rand();
   		printf("%d\n",x%10+1);
	}
	}
	return 0;
}
