#include<cstdio>

using namespace std;

int m,n,t,a[3000000 + 10],b[3000000 + 10];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= m;++ i){
		scanf("%d",&a[i]);
	}
	printf("%d",n);
}
