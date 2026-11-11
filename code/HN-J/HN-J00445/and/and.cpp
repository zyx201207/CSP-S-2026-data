#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
bitset<30> data[N];
int n, m, s = 29, p = 29;

bool cmp(bitset<30> x, bitset<30> y){
	int i = p;
	while(i >= 0){
		if(x[i] != y[i]){
			return (x[i] > y[i]);
		}
		i--;
	}
	return false;
}

signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	unsigned long long c, maxn = 0;
	int p1 = 0;
	for(int i = 1; i <= n; i++){
		cin >> c;
		data[i] = c;
		if(c > maxn){
			maxn = c;
			p1 = i;
		}
	}
	//sort(data+1, data+n+1, cmp);
	s = 29;
	while(data[p1][s] == 0) s--;
	for(int pos = s; pos >= 0; pos--){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(data[i][pos] == 1){
				sum++;
			}
			if(sum >= m) break;
		}
		if(sum >= m){
			p = pos;
			break;
		}
	}
	sort(data+1, data+n+1, cmp);
	bitset<30> ans = data[1]&data[2];
	for(int i = 3; i <= m; i++){
		ans &= data[i];
	}
	int r = 0;
	for(int i = 0; i < 30; i++){
		r += ans[i]*(pow(2, i));
	}
	cout << r;
	return 0;
}
