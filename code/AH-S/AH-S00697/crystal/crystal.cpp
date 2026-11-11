#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans=1;
long long m,sum,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int j=1,i=2;i<=n;i++){
		sum+=1ll*(i-j)*(a[i]-a[i-1]);
		while(j<i&&sum>m) sum-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
