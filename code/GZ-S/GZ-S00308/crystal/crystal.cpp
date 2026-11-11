//GZ-S00308 贵阳市第十七中学 徐廷蔚 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
bool check(int x,int r) {
	long long d = a[r + 1];
	long long cost = (long long)(r - x + 1) * d - (s[r] - s[x - 1]);
	return cost <= m; 	
}
int ans = -1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i ++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i ++) {
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1;i <= n;i ++) {
		int l = 1,r = i - 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(check(mid,i - 1)) r = mid;
			else l = mid + 1;
			//cout << l << " " << r <<"\n";
		}
//		int j = i;
//		while(j <= n && a[j] == a[i]) {
//			j ++;
//		}
//		i = j;
		ans = max(ans,i - l + 1);
		//cout << l << " " << j << "\n";
	}
	cout << ans;
	return 0;
}
