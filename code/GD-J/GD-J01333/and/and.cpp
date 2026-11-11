#include<bits/stdc++.h>
#define int long long
#define per(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,y,x) for(int i=y;i>=x;i--)
using namespace std;
int n,m,a[200005],ans;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	per(i,1,n) cin>>a[i];
	stable_sort(a+1,a+n+1);
	per(i,1,n-m+1) {
		int x=a[i];
		per(j,i+1,i+m-1) x&=a[j];
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
