#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans,l,r,mid;
ll m;
ll a[N],sum[N];
bool check(int L,int R) {
	return sum[R]-sum[L-1]+m>=(R-L+1)*a[R];
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		l=i; r=n;
		while(l<r) {
			mid=(l+r+1)>>1;
			if(check(i,mid)) l=mid;
			else r=mid-1;
		}
		if(check(i,l)) ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
// O(n log n).
// 相信相信的力量吧
// 希望能 1= 呀
