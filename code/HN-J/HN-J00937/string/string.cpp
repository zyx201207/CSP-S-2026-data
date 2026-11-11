#include<bits/stdc++.h>
using namespace std;
int tmp_n;
const int N = 2e5 + 5;
struct P{
	long long v;
	char c;
}a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> tmp_n;
	int n = 0;
	while(tmp_n--){
		int i;
		char cc;
		cin >> i>> cc;
		if(n == 0){
			n += 1;
			a[n].v = i;
			a[n].c = cc;
		}else if(a[n - 1].c != cc){
			n += 1;
			a[n].v = i;
			a[n].c = cc;
		}else{
			a[n].v += i;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	int l = 1, r = n;
	int cnt = 0;
	while(l <= r){
		if(a[l].v == a[r].v){
			if(a[l].c != a[r].c){
				cnt += a[l].v;
			}
			l++;
			r--;
		}else if(a[l].v > a[r].v){
			if(a[l].c != a[r].c){
				cnt += a[r].v;
			}
			a[l].v -= a[r].v;
			r--;
		}else{
			if(a[l].c != a[r].c){
				cnt += a[l].v;
			}
			a[r].v -= a[l].v;
			l++;
		}
	}
	cout << cnt;
	return 0;
}

