#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long num;
int a[200005];
char c[200005];
void solve(){
	int r = 1, l = n;
	while (r < l){
		if (c[r] != c[l]) {
			num += min(a[r], a[l]);
			if (a[r] > a[l]) {
				c[l] = c[r];
				a[r] -= a[l];
				l -= 1;
			}else if (a[r] < a[l]){
				c[r] = c[l];
				a[l] -= a[r];
				r += 1;
			}else if (a[r] == a[l]) {
				r += 1;
				l -= 1;
			}
		}else {
			if (a[r] > a[l]) {
				a[r] -= a[l];
				l -= 1;
			}else if (a[r] < a[l]){
				a[l] -= a[r];
				r += 1;
			}else if (a[r] == a[l]) {
				r += 1;
				l -= 1;
			}
		}
	}
	cout << num << endl;
	return ;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
    	cin >> a[i] >> c[i];
	}
	solve();
	return 0;
} 
