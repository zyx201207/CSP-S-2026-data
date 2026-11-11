#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010];
void solve(){
	cin>>n>>d;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (a[n]-a[1]<=10*d){
		cout<<0<<endl;
		return ;
	}
	cout<<0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		solve();
	}
	
	return 0;
}
