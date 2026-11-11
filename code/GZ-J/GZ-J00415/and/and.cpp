//GZ-J00415 兴义市弘毅中学 程峻熙 
#include<bits/stdc++.h>
using namespace std;
long long a,b[1000010],c,d=(1<<31)-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&a,&c);
	for(int i=1;i<=a;i++){
		scanf("%lld",&b[i]);
	}
	sort(b+1,b+1+a);
	for(int i=1;i<=c;i++){
		d=d&b[i];
	}
	printf("%lld",d);
	return 0;
}
