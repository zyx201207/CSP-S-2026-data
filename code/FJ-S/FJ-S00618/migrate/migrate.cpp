#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d",&c,&t);
	while(t--) printf("%d",rand()%10000+1);
	return 0;
}
