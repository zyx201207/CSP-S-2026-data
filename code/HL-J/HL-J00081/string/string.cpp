#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long a[200002],s[200002];
char b[200002];
long long sum = 0;
long long ans = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		sum += a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	long long l = 0,r = n,cl = 0,cr = sum;
	for (int i = 1;l < r;i++){
		long long bl = cl;
		long long br = cr;
//		cout << s[l + 1] << ' ' << sum - s[r - 1] << endl;
		if (s[l + 1] <= sum - s[r - 1]){
			l++;
			cl = s[l];
			cr = sum - cl;
//			cout << l << ' ' << r << ' ';
//			cout << cl << ' ' << cr << ' ';
			if (l >= r){
//				cout << ans << endl;
				break;
			}
			if (b[l] != b[r]){
				ans += (cl - bl);
			}
//			cout << ans << endl;
		} else {
			r--;
			cr = s[r];
			cl = sum - cr;
//			cout << l << ' ' << r << ' ';
//			cout << cl << ' ' << cr << ' ';
			if (l >= r){
//				cout << ans << endl;
				break;
			}
			if (b[r] != b[l]){
				ans += (br - cr);
			}
//			cout << ans << endl;
		}
	}
	cout << ans;
}
