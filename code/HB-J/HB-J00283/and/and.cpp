#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],ans=0,f[200005][20];
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	for(int j=1;j<=17;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=f[i][j-1]&f[i+(1<<(j-1))][j-1];
		}
	}
	int dui=log2(m);
	for(int i=1;i+m-1<=n;i++){
		ans=max(ans,f[i][dui]&f[i+m-(1<<(dui))][dui]);
	}
	printf("%lld",ans);
	return 0;
}
