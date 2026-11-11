#include <bits/stdc++.h> 
using namespace std;
long long n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string s="";
	for(long long i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		for(long long j=1;j<=x;j++)s+=c;
	}
	long long m = s.size(), cnt = 0;
	for(long long i = 0; i < m/2; i++) {
		if(s[i] != s[m-i-1])cnt++;
	}
	cout << cnt;
	return 0;
}
