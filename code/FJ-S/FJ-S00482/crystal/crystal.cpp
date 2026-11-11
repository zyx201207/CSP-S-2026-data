#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;

int n,m,a[N],ans;
int g;

void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	g = a[2] - a[1];
	if(n > 5000){
		int sum = 0;
		for(int i=1;i<n;i++){
			sum += g*i;
			if(sum > m){
				cout << i;
				return;
			}
		}
		cout << n;
		return;
	}
	for(int i=2;i<=n;i++){
		int sum = 0;
		for(int j=i-1;j>=1;j--){
			sum += a[i] - a[j];
//			cout << sum << " ";
			if(sum > m)break;			
			ans = max(ans,i-j+1);
		}
//		cout << '\n';
	}
	cout << ans;
	return;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--)solve();
	return 0;
}
/*

5 2
-3 -1 6 6 7 10
2  7  0 1
8  8  1 1
18 10 2 1
*/
