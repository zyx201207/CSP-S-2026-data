#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e5 + 5;
int n,m,a[MAXN],ans = -1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a + n);
	for(int i = 1;i < n;i++){
		if(a[i] == a[i - 1]) continue;
		int t = m,tans = 1;
		for(int j = i - 1;j >= 0;j--){
			if(a[j] + t >= a[i]){
				t -= a[i] - a[j];
				tans++;
			}else break;
		}
		ans = max(ans, tans);
	}
	cout << ans;
	return 0;
}
