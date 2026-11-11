#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n, m, a[N], dif[N], qzh[N];
int qj_equal(int l, int r){
	int sum = 0;
	for(int i = 0; i <= (r - l + 1) >> 1; i++){
		sum += qzh[r] - qzh[l - 1 + i];
	}
	return sum;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dif[1] = 0;
	for(int i = 2; i <= n; i++){
		dif[i] = a[i] - a[i - 1];
	}
	qzh[0] = 0;
	for(int i = 1; i <= n; i++){
		qzh[i] = qzh[i-1] + dif[i]; 
	}
	int max_quantity = -3077;
	int qj_lenth;
	for(int i = 1; i <= n; i++){
		for(int ii = i; ii <= n; ii++){
			qj_lenth = ii - i + 1;
			if(qj_equal(i, ii) <= m && qj_lenth >= max_quantity){
				max_quantity = qj_lenth;
			}
		}
	}
	cout << max_quantity + 1;
	return 0;                                                           
}
