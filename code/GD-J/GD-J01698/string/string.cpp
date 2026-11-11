#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	int l_ = a[1], r_ = a[n];
	long long ans = 0;
	while(l <= r){
		if(c[l] == c[r]){
			if(l_ < r_){
				r_ -= l_;
				l++;
				l_ = a[l];
			}
			else if(l_ > r_){
				l_ -= r_;
				r--;
				r_ = a[r];
			}
			else{
				l++;
				r--;
				l_ = a[l];
				r_ = a[r];
			}
		}
		else{
			if(l_ < r_){
				r_ -= l_;
				ans += l_;
				l++;
				l_ = a[l];
			}
			else if(l_ > r_){
				l_ -= r_;
				ans += r_;
				r--;
				r_ = a[r];
			}
			else{
				ans += l_;
				l++;
				r--;
				l_ = a[l];
				r_ = a[r];
			}
		}
	}
	cout << ans;
	return 0;
}
