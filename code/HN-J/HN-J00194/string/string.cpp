#include<bits/stdc++.h>
using namespace std;

string s;
long long min_num, min_gcd = 1;
bool gcd_tr;
long long a[200005] , n, sum;
char b[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (long long i = 1; i <= n; i ++){
		cin >> a[i] >> b[i];
		min_num = min (min_num, a[i]);
	}
	
	for (long long i = min_num; i >= 2; i --){
		for (int j = 1; j <= n; j ++){
			if (a[j] % i != 0) {
				gcd_tr = false;
				break;
			}
		}
		if (gcd_tr = true){
			min_gcd = i;
			break;
		}
	}
	
	for (long long i = 1; i <= n; i ++){
		for (int j = 1; j <= a[i] / min_gcd; j ++){
			s += b[i];
		}
	} 
	
	int sizs = s.size();
	for (long long i = 0; i < (sizs + 1) / 2; i ++){
		if (s[i] != s[sizs - i - 1]) sum ++;
	}
	cout << sum * min_gcd;
	return 0;
}

