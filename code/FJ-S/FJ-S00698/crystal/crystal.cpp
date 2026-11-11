#include <cstdio>
#include <algorithm>
#define N 500005
using namespace std;

int n, len, ans;
long long a[N], pre[N], base, m;

int main(){
	freopen("crystal4.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1, r=1;
	while(l <= r && r <= n){
		len=r-l+1;
		base=len*a[r];
		if(base-pre[r]+pre[l-1] <= m){
			ans=max(ans, len);
			r++;
		}
		else{
			l++;
		}
	}
	printf("%d", ans);
	return 0;
}
