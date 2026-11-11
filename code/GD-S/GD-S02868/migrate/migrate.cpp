#include <bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
long long vis[2000005];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t --){
		long long n,d;
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
			if(i == 1){
				vis[1] = a[1];
			}
			vis[i] = vis[i-1]+a[i];
		}
		if(d == 1){
			cout << 0 <<"\n";
			continue;
		}
		if(d * 2 - 1> a[n]-a[1]){
			cout << 0 << "\n";
			continue;
		}
		for(int i = 1 ,j = 1,q = 1; i <= n ; i ++){
			if(a[i]-a[j] > d * 2 - 1){
				j ++;
			}
			if(a[i]-a[j] == d * 2 - 1){
				ans ++;
				q ++;
				i = q;
			}
		}
		cout << ans / 2<< "\n";
	}
	return 0;
}
