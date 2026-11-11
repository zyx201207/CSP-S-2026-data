#include <bits/stdc++.h>
#define Wakamiya_eve return 0
#define int long long
using namespace std;
const int N=5e5+947;
int n,m,maxn=-1;
int a[N];
int b[N];
int pre[N];
int check(int r,int l) {
	//cout<<pre[r]-pre[l-1]<<' '<<a[r]*(r-l+1)<<'\n';
	return pre[r]-pre[l-1]+m>=a[r]*(r-l+1);
}
signed main() {

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
	for(int i=1; i<=n; i++) {
		int l=i,r=n;
		int ans;
		while(l<=r) {
			//cout<<l<<' '<<r<<endl;
			int mid=l+(r-l)/2;
			if(check(mid,i)) ans=mid,l=mid+1;
			else r=mid-1;

		}
		//cout<<ans<<endl;
		maxn=max(ans-i+1,maxn);
	}
	cout<<maxn;
	Wakamiya_eve;
}
