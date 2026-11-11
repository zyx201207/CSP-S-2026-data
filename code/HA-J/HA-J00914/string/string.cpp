#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, cnt = 0;
	string s;
	cin >> n;
	for(long long i = 1;i <= n;i++){
		long long a;
		cin >> a;
		char b;
		cin >> b;
		for(long long j = 1;j <= a;j++){
			s += b;
		}
	}
	for(long long i = 0;i <= s.size() / 2;i++){
		long long j = s.size() - 1;
		if(s[i] != s[j]){
			cnt++;
			j--;
		}
		else{
			j--;
		}
	}
	cout << cnt;

	return 0;
} 
