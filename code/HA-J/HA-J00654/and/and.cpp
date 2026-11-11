#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;++i) ans&=a[i];
		printf("%lld",ans);
	}
	else if(m==1){
		for(int i=1;i<=n;++i) ans=max(ans,a[i]);
		printf("%lld",ans);
	}
	else{
		for(int i=1;i<=n;++i){
			long long maxv=0;
			for(int j=i+1;j<=n;++j){
				long long k=a[i];k&=(long long)a[j];
				maxv=max(maxv,k);
			}ans=max(ans,maxv);
		}
		printf("%lld",ans);
	}
	return 0;
}
