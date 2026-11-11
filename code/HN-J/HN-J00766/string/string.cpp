#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;

struct Node{
	char c;
	int len;
}a[maxn];

int n;
ll cnt;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].len >> a[i].c;
	}
	int l = 1, r = n;
	while(l <= r){
		if(a[l].len < a[r].len){
			a[r].len -= a[l].len;
			cnt += (a[l].c == a[r].c) ? 0 : a[l].len;
			l++;
		}else{
			a[l].len -= a[r].len;
			cnt += (a[l].c == a[r].c) ? 0 : a[r].len;
			r--;
		}
	}
	cout << cnt;
	return 0;
}

