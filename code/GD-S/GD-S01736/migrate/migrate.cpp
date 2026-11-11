#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
int c,t,n;
ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	cin >> c >> t;
	if(c == 0 || c == 11 || c == 12){
		while(t--){
			cin >> n >> d;
			for(int i = 1;i <= n;i++)
				cin >> x[i];
			sort(x + 1,x + 1 + n);
			int loc = -1;
			ll cha = x[n] - x[n - 1];
			if(cha * 2 > d){
				cout << 0 << endl;
				continue;
			}
			ll num = d + cha;
			for(int i = 1;i <= n;i++){
				if(x[i] - x[1] == num){
					loc = i;
					break;
				}
			}
			ll ans = n - loc + 1;
			cout << ans << endl;
		}
	}
	return 0;
}
