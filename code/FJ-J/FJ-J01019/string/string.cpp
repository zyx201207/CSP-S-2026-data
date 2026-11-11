#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],l,r,ans;char b[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	l=1;r=n;
	while(l<r) {
		int x=a[l],y=a[r];
		if(b[l]!=b[r]) ans+=min(a[l],a[r]);
		if(x>y) a[l]-=a[r],r--;
		if(x<y) a[r]-=a[l],l++;
		if(x==y) l++,r--;
	}
	cout<<ans;
	return 0;
}
