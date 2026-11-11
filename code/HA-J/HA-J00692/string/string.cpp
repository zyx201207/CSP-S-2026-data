#include<bits/stdc++.h>
using namespace std;

int n;
long long sum;
int a[2000100];
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		char x;
		cin >> x;
		for(int j = 1; j <= a[i]; j ++) s += x;
	}	
	
	
	long long ans = 0;
	for(int i = 0, j = s.size() - 1; i != j; i ++, j --){
		if(s[i] != s[j]) ans ++;
	}
	
	cout << ans;
	
	
	return 0;
}
