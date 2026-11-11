#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2*1e5+3;

int n,ans;
int a[N];
char c[N];

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r) {
		if(a[l]==a[r]&&c[l]==c[r]) {
			l++;
			r--;
		}
		int delta=min(a[l],a[r]);
		if(c[l]==c[r]) {
			a[l]-=delta;
			a[r]-=delta;
		}
		else {
			ans+=delta;
			a[l]-=delta;
			a[r]-=delta;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
}
