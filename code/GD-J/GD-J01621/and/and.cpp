#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],ans;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
