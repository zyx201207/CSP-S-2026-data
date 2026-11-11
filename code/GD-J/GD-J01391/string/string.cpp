#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
struct Node{
	long long b;
	char c;
}a[N];
long long ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i].b;
		cin >> a[i].c;
	}
	int l = 1, r = n;
	while(l < r){
		if(a[l].b < a[r].b){
			if(a[l].c != a[r].c){
				ans += a[l].b;
			}
			a[r].b -= a[l].b;
			l++;
		}
		if(a[l].b > a[r].b){
			if(a[l].c != a[r].c){
				ans += a[r].b;
			}
			a[l].b -= a[r].b;
			r--;
		}
		if(a[l].b == a[r].b){
			if(a[l].c != a[r].c){
				ans += a[r].b;
			}
			l++;
			r--;
		}
	}
	cout << ans << endl;
	return 0;
}
