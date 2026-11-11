//GZ-J00539 兴义市弘毅中学 欧阳锦田
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],num;
bool cmp(long long b,long long c){
	return b>c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	num=a[0];
	for(long long i=1;i<m;i++){
		num=num&a[i];
	}
	printf("%lld",num);
	return 0;
}
