#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n; 
	vector<ll> a(n + 5);
	vector<char> c(n + 5);
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	ll ans = 0;
	for(int i = 1, j = n; i <= j; ){
		if(a[i] >= a[j]){
			if(c[i] != c[j]) ans += a[j];
			a[i] -= a[j];
			j--;
		}else{
			if(c[i] != c[j]) ans += a[i];
			a[j] -= a[i];
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}
