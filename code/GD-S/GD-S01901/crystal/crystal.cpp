#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i=(l);i<=(r);i++)
#define per(i,l,r) for (int i=(l);i>=(r);i--)

using namespace std;

const int N=5e5+10;

int n,m,a[N],s[N];

signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	
	int ans=1;
	rep(i,1,n){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1]) <= m){
				r=mid;
			} else {
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}	
	
	cout<<ans;
	
	return 0;
}
