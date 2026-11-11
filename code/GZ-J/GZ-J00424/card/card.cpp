//GZ-J00424 张云景 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		f[a[i]]=max(f[a[i]],i);
	}
	for(int i=1;i<=m;i++){printf("%lld ",f[i]);}
	printf("\n");
	return 0;
}
