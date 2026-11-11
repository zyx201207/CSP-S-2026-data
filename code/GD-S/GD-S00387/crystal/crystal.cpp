#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll a[maxn];
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n; ll m; scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll sum=0; int ans=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=a[i];
		while(j<=i&&1ll*a[i]*(i-j+1)-sum>m) sum-=a[j],j++;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
