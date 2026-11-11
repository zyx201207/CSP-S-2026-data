#include <bits/stdc++.h>
#define MAXN 500005
using ll = long long;
using namespace std;
int n;
ll m,a[MAXN],s[MAXN];
bool chk(int l,int r){
	ll cst = a[r]*(r-l+1) - (s[r]-s[l-1]);
	return cst<=m;
}
int main(){
#ifndef SVK
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i] = s[i-1]+a[i];
	int l=1, ans = 0;
	for(int i=1;i<=n;i++){
		while(l<=i && !chk(l,i))l++;
		ans = max(ans, i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}


