#include<bits/stdc++.h>
#define int long long
#define per(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,y,x) for(int i=y;i>=x;i--)
using namespace std;
int n,m,a[500005],ans;
bool check(int mid) {
	int sum=0;
	per(i,1,mid-1) sum+=a[mid]-a[i];
	return sum<=m;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	per(i,1,n) cin>>a[i];
	if(m==0) {
		per(i,1,n) {
			int cnt=0;
			per(j,1,n) if(a[j]==a[i]) cnt++;
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	stable_sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(mid<1 || mid>n) continue;
		if(check(mid)) l=mid+1,ans=max(ans,mid);
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
