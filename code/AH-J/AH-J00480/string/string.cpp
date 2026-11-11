#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
struct node{
	ll s;
	char val;
}a[N];
ll n, sum = 0, cnt = 0, id, ans = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].s >> a[i].val;
	}
	int l = 1, r = n, sl = a[1].s, sr = a[n].s;
	while(l < r){
//		cout << l << ' ' << r << endl;
		if(sr >= sl){
			if(a[r].val == a[l].val) {
				a[l].s -= sl;
				a[r].s -= sl;
				sr -= sl;
				sl = 0;
			}
			else{
				ans += a[l].s;
				a[l].s -= sl;
				a[r].s -= sl;
				sr -= sl;
				sl = 0;
			}
			l ++;
			sl += a[l].s;
		}
		if(sl >= sr){
			if(a[r].val == a[l].val) {
				a[l].s -= sr;
				a[r].s -= sr;
				sl -= sr;
				sr = 0;
			}
			else{
				ans += a[r].s;
				a[l].s -= sr;
				a[r].s -= sr;
				sl -= sr;
				sr = 0;
			}
			r --;
			sr += a[r].s;
		}
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
