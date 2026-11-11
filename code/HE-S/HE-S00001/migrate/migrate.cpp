#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;int ans=0;
		for(int i=1;i<=n;i++)cin >> a[i];
		if(d<a[2]-a[1]){cout << "0 ";continue;}
		for(int i=1;i<=n;i++){
			ans+=(n-i-1)/2;
		}cout << ans << ' ';
	}
	return 0;
}
