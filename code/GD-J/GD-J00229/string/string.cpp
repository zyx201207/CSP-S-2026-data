#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005
int n,m,a[N],ans,v[N],vis[N];
char b[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	for(int i=1; i<=n; i++) {
		if(b[i]!=b[n-i+1]) {
			ans+=min(a[i],a[n-i+1]);
			if(a[i]>=a[n-i+1]) {
				b[n-i+1]=b[i];
				ans+=a[i]-a[n-i+1];
			} else {
				b[i]=b[n-i+1];
			ans+=a[n-i+1]-a[i];
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
