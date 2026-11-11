#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
bool cmp(int x,int y) {
	return x<y;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=1,cnt=1;
	for(int i=1; i<=n; i++) {
		if(cnt*(a[i+1]-a[i])<=m) {
			ans++;
			m=m-cnt*(a[i+1]-a[i]);
			cnt++;
		} else {
			break;
		}
	}
	cout<<ans<<endl;

	return 0;
}
