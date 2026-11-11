#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
long long n,m,ans,a[MAXN],sum[MAXN];
bool cmp(long long x,long long y){
	return x > y;
}
bool check(long long x,long long len){
	if(x+len>n) return false;
	long long cnt = sum[x+len]-sum[x-1];
	return a[x]*(len+1)-cnt<=m;
}
long long f(long long x){
	long long L = 0,R = n,res = 0;
	while(L<=R){
		long long mid = (L+R)/2;
		if(check(x,mid)) L = mid+1,res = mid;
		else R = mid-1;
	}
	return res+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	for(int i = 1;i<=n;i++) ans = max(ans,f(i));
	cout << ans;
	return 0;
}
