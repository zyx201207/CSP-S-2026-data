//GZ-J00416 代正维 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200015],i,j,c,ans[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	printf("%lld",a[n-m]);
	return 0;
} 
