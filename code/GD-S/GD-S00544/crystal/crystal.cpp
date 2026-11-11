#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N],s[N];
int ans;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int ps=1;
	for(int i=1;i<=n;i++) {
		while(ps<=i&&(i-ps+1)*a[i]-(s[i]-s[ps-1])>m) ps++;
		ans=max(ans,i-ps+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7

*/
