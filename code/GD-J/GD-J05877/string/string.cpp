#include <iostream>
#include <string>
#include <cmath>
//#define int __int128
using namespace std;

int n;
int arr[200005];
char c[200005];
long long d[200005];
long long s;
long long ans;

signed main (){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)    cin >> arr[i] >> c[i];
	for (int i = 1;i <= n;i++) {
		s += arr[i];
		d[i] = d[i - 1] + arr[i];
//		leng[i] = d[i] - d[i - 1];
	}
	long long l = 1, r = n;
	long long dl = 1, dr = s;
	while (dl <= dr && l <= r){
		if (c[l] != c[r]){
			ans += min(d[l] + 1 - dl, dr - d[r - 1]);
//			cout << ans;
		}
		if (d[l] + 1 - dl < dr - (d[r - 1])){
			dr -= (d[l] - dl + 1);
			dl = d[l] + 1;
			l++;
		}
		else if (d[l] + 1 - dl == dr - (d[r - 1])){
			dr = d[r - 1];
			dl = d[l] + 1;
			l++;
			r--;
		}
		else {
			dl += dr - d[r - 1];
			dr = d[r - 1];
			r--;
		}
	}
	cout << min(ans, s - ans);
	return 0;
}
