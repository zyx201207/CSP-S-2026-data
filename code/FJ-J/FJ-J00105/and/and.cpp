#include <bits/stdc++.h>
using namespace std;

int a[200010];
int up = 1, sum = 0;
bool cmp(int x, int y){
	int a = (x / up % 2);
	int b = (y / up % 2);
	if (a && !b){
		if (x > y){
			return x > y;
		}return x < y;
	}else if (!a && b){
		if (x > y){
			return x < y;
		}return x > y;
	}return x < y;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];	
	}sort(a+1, a+n+1);
	while(up < a[n]){
		up *= 2;
	}up /= 2;
	for(;up >= 1;up /= 2){
		sort(a+1, a+n+1, cmp);
		int l = 1, r = n, ans = 0;
		while(l <= r){
			int M = (l + r) / 2;
			if (a[M] / up % 2 == 1){
				ans = M;
				l = M + 1;
			}else{
				r = M - 1;
			}
		}if (ans >= m){
			sum += up;
			n = ans;
		}
	}cout << sum;
	return 0;
}
