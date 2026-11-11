#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
ll s[maxn], a[maxn];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		s[i] = s[i-1]+a[i];  //前缀和 
	} 
	int ans = 0;
	int l, r, mid;
	for(int i=n;i>=1;i--){  //求和到i的最大值 
		l = 1;r=i;int res = i;
		while(l<=r){  //二分满足条件的最前位置 
			mid = l+((r-l)>>1);
			if(abs(s[i]-s[mid-1]-a[i]*(i-mid+1)) <= m){
				res = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		ans = max(ans, i-res+1);
	}
	printf("%d", ans);
	return 0;
}
