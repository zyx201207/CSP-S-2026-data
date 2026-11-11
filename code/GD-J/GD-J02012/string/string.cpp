#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int N = 2e5 + 5;

void miku(){
	
	string s;
	
	int n; cin >> n;
	long long sum = 0;
	for (int i = 1;i <= n;i ++){
		long long x; cin >> x;
		char c; cin >> c;
		for (long long i = sum;i < x + sum;i ++) s[i] = c;
		sum += x;
	}
	
	long long ans = 0;
	long long l = 0, r = sum - 1;
	while(l <= r){
		if (s[l] != s[r]) ans ++;
		l ++, r --;
	}
	
	cout << ans;
	
	return ;
}

int main(){
	
	freopen("string.in", "r" , stdin);
	freopen("string.out", "w" , stdout);
	
	miku();
	
	return 0;	
}
