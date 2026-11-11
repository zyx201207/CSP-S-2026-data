#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5;
int n;
ll a[N + 5];
string c[N + 5];
ll ans = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for (int i = 1, j = n; i <= j;){
		if(c[i] == c[j]){
			ll sub = min(a[i], a[j]);
			ll maxn = max(a[i], a[j]);
			if (a[i] == a[j]){
				a[i] = 0;
				a[j] = 0;
				i++;
				j--;
			}
			else if (maxn == a[i]){
				a[i] -= sub;
				a[j] = 0;
				j--;
			}
			else if (maxn == a[j]){
				a[j] -= sub;
				a[i] = 0;
				i++;
			}
		}else{
			ll minn = min(a[i], a[j]);
			ans += minn;
			if (a[i] == a[j]){
				a[i] = 0;
				a[j] = 0;
				i++;
				j--;
			}
			else if (minn == a[i]){
				a[i] = 0;
				c[i] = c[j];
				a[j] -= minn;
				i++;
			}
			else if (minn == a[j]){
				a[j] = 0;
				c[j] = c[i];
				a[i] -= minn;
				j--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
