#include <bits/stdc++.h>
using namespace std;
long long a[26];
char b[26];
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	long long n;
	cin >> n;
	long long a_[n];
	char b_[n];
	for (long long i = 0;i < n;i ++ ){
		cin >> a_[i] >> b_[i];
	}
	long long m_ = 0;
	for (long long i = 0;i < n;i ++ ){
		a[int(b_[i] - 97)] += a_[i];
	}
	long long n_ = 0;
	for (long long i = 0;i < 26;i ++ ){
		m_ = max(m_,a[i]);
		if (a[i] != 0) n_ += a[i];
	} 
//	cout << _m; 
	if (n % 2 == 1) cout << n_ - 1 - m_;
	else cout << n_ - m_;
	return 0;
}
