#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 10;
ll a[maxn],sum[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int l = 0,r = i;
		while(r - l > 1){
			int mid = (l + r) >> 1; 
			if(a[i] * (i - mid + 1) - (sum[i] - sum[mid-1]) <= m)r = mid;
			else l = mid;
		}
		ans = max(ans,i - r + 1);
	}
	printf("%d",ans);
}
