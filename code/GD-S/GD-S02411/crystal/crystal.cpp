#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n,m,ans;
ll a[N],arr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)arr[i]=arr[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=0,r=i-1,mid,idx=0;
		while(l<=r){
			mid = l+r>>1;
			if((a[i]*(i-mid))-(arr[i]-arr[mid])<=m){
				r = mid-1;
				idx = mid;
			}else l = mid+1;
		}ans = max(ans,i-idx);
		//cout << ans << " "<< idx << "\n";
	}
	printf("%lld",ans);
	return 0;
}
