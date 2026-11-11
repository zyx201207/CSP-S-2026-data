#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pint;
const int N=1e6+114;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(m>=a[i]*(i-mid+1)-(sum[i]-sum[mid-1])) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans << endl;
	return 0;
}
