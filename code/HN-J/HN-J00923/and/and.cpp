#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], cnt, sum, sum1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i ++){  
		int sum = a[i] & a[i + 1];
		int sum1 = a[i + 1] & a[i + 2];
		int sum2 = a[i + 2] & a[i + 3];
		int sum4 = a[i + 3] & a[i + 4];
		int sum5 = a[i + 4] & a[i + 5];
		int sum3 = a[i + n - 1] & a[i + n];
		cnt = max(sum, sum1);
		cnt = max(cnt, sum2);
		cnt = max(cnt, sum4);
		cnt = max(cnt, sum5);
		cnt = max(cnt, sum3);
	}
	cout << cnt;
	return 0;
} 
