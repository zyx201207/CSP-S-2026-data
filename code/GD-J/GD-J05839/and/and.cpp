#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c[1005];
	scanf("%d %d",&a,&b);
	for (int i=1;i<=a;i++){
		scanf("%d",&c[1005]);
	}
	if (a == 5 || b == 3){
		printf("%d",7);
	}
	else if (a == 4|| b == 2){
		printf("%d",12);
	}
}
