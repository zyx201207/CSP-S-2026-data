#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int n;
ll x[N], d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, T;
	cin >> c >> T;
//	if(c == 11 || c == 12){
		while(T--){
			cin >> n >> d;
			for(int i(1); i <= n; i++) cin >> x[i];	
	//				printf("n=%d d=%lld d_=%lld\n",n,d,d/(x[2]-x[1]));
			ll d_ = d / (x[2] - x[1]);
			if(d_ <= 1){
				putchar('0'), putchar('\n');
				continue;
			}
			if(d_ >= n - 1){
				putchar('0'), putchar('\n');
				continue;
			}
			cout << max(0ll, n - d_ * 2 + 1) << '\n';
		}
//	}
	
	return 0;
}
