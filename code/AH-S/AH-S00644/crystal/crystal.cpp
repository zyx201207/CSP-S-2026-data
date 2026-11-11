#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long tmp,n,m,sum[N],a[N],ans,sumk,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf ("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
		sum[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		tmp++;
		ans+=tmp*sum[i];
		sumk+=sum[i];
		while (ans>m){
			ans-=sumk;
			sumk-=sum[i-tmp+1];
			tmp--;
		}
		mx=max(mx,tmp);
	}
	printf("%lld",mx+1);
	return 0;
}
