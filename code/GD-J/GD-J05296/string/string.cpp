#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5 + 1;
int n, num[N], l, r;
char c[N];
long long ans;
int k;
char kc;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i] >> c[i];
	}
	l = 1;
	r = n;
	while(l <= r){
		if(num[l] < num[r]){
			if(c[l] != c[r]){
				ans += num[l];
			}
			num[r] -= num[l];
			num[l] = 0;
			l++;
		}else if(num[l] > num[r]){
			if(c[l] != c[r]){
				ans += num[r];
			}
			num[l] -= num[r];
			num[r] = 0;
			r--;
		}else{
			if(c[l] != c[r]){
				ans += num[l];
			}
			num[l] = 0;
			num[r] = 0;
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
