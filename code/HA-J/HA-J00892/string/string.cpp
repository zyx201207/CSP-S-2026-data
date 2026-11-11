#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		long long x;
		char c;
		cin >> x >> c;
		for (int j = 1;j<=x;j++){
			s=s+c;
		}
	}
	long long l = s.size(), cnt = 0;
	for (long long i = 0;i<l-1-i;i++){
		if(s[i]!=s[l-1-i]) cnt++;
	}
	cout << cnt;
	return 0;
}
