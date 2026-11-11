#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long l=1;
	for(int i=1;i<=n;++i){
		sum-=a[i];
		while((i-l+1)*a[i]+sum>m) sum+=a[l++];
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
