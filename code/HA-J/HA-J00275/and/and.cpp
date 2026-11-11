#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=2e5+5;
long long a[maxn];
long long ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans=ans&a[i];
	}
	printf("%lld",ans);
	return 0;
}
