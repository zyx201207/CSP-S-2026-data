#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans;
long long m,a[500005],pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++){
		while(l<=r && (r-l+1)*a[r]-(pre[r]-pre[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
