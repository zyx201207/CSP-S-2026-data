#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, cnt = 0, sum = 0;
	string s;
	cin >> n;
	for(long long i = 0; i < n; i++){
		int b;
		string c;
		cin >> b >> c;
		sum += b; 
		for(long long j = 0; j < b; j++){
			s += c;
		}
	}
	for(long long i = 0; i < sum; i++){
		if(s[i] != s[sum - i]){
			cnt++;
		}
	}
	
	if(sum % 2 == 0){
		cout << cnt / 2 + 1;
	}
	else{
		cout << cnt - 1;
	}
	return 0;
}
