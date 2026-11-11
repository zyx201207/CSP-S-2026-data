//GZ-J00539 兴义市弘毅中学 欧阳锦田
#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
bool b=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	}
	for(long long i=1;i<=n;i++){
		if(c[i]!=c[n-i+1]) b=0;
	}
	if(b==1){
		printf("0");
	}
	else printf("2");
	return 0;
}
