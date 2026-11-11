#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+10;
int c,t,a[N],m,n;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&a[i]);
		}
		if(a[3]-a[2] == a[n]-a[n-1]){
			if(m <= a[2]-a[1]){
				cout << 0 << '\n';
				continue;
			}else{
				if(n>m*2+1){
					cout << n-m*2+1 << '\n';
				}else{
					cout << 0 << " ";
				}
			}
			continue;
		}
		cout << 0 << '\n';
	}
	return 0;
}
