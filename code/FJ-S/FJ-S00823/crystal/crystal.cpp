#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],l=1,r,sum,cnt,ans;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(true) {
		++r;
		if(r>n) break;
		sum+=cnt*(a[r]-a[r-1]);
		while(sum>m) sum-=a[r]-a[l],l++;
		cnt=r-l+1;ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
