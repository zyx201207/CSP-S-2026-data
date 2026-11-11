#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
const int N=2e5+5;
int n,a[N],l=1,r;
char c[N];
ll ans,sizl,sizr;
signed main() {
	IOS
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	r=n;
	for(int i=1;i<=n;++i) cin >> a[i] >> c[i];
	sizl=a[l],sizr=a[r];
	while(l<=r) {
		if(sizl>=sizr) {
			if(c[l]!=c[r]) ans+=sizr;
			sizl-=sizr;
			//if(!sizl) sizl=a[++l];
			sizr=a[--r];
		}
		else {
			if(c[l]!=c[r]) ans+=sizl;
			sizr-=sizl;
			//if(!sizr) sizr=a[--r];
			sizl=a[++l];
		}
	}
	cout << ans;
	return 0;
}
