#include<bits/stdc++.h>
#define MAX_N 500010
#define int long long
using namespace std;
int n,m;
int a[MAX_N],pre[MAX_N];
int ans = 1,l = 0;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		pre[i] = pre[i-1] + a[i];
	}
	for(int i=2;i<=n;i++) {
		int diff = a[i] * (i-l-1) - (pre[i-1]-pre[l]);
		while(diff > m && l < i) {
			l++;
			diff = a[i] * (i-l-1) - (pre[i-1]-pre[l]);
		}
		ans = max(ans, i-l);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
