#include<bits/stdc++.h>
#define int long long
#define uint long long
using namespace std;
int n,m,a[500010],z;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		z+=(a[i]-a[i-1])*(i-1);
		if(z>m){cout<<i-1;return ;}
	}
	cout<<n;
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
