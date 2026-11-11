//GZ-J00528 陈文谦 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);long long a[n+1]={0};
	for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
	sort(a+1,a+n+1,greater<long long>());
	printf("%lld",a[m]);
	return 0;
} 
