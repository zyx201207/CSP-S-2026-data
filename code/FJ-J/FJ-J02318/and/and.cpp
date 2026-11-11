#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//const int N=1e5+10;
int n,m,a[200010],mx;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	cout<<mx;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
