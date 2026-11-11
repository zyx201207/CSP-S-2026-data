#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[2*100000+5];
int main() {
	freopen(".\\and.in", "r", stdin);
	freopen(".\\and.out", "w", stdout);

	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(j==i)continue;
			ans=max(ans,(i&j));
		}
	}
	cout<<ans;
	return 0;
}
