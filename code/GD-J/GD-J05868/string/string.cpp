#include <iostream>
using namespace std;
int n, a[200005];
long long ans, mid, midn;
char c[200005];
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	mid = s.size() / 2 - !(s.size() % 2 == 1);
	for (int i = mid + 1; i < s.size(); i++){
		if (s[i] != s[s.size() - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
