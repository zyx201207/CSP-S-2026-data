#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define x first
#define y second
#define endl '\n'
using namespace std;
const int N=5e5+10;
int sum[N],n,m,a[N],ans;
void solve() {
	cin>>n>>m;
	upp(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	upp(i,1,n) {
		sum[i]=sum[i-1]+a[i];
	}
	upp(i,1,n) {
		int l=1,r=i;
		while(l<r) {
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int tt=1;
	while(tt--) solve();
	return 0;
}
