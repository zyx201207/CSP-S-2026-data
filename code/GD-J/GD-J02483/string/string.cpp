#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[2005];
	char ch[2005];
	int n;
	cin >> n;
	string s = "";
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> ch[i];
		for(int j = 1; j <= a[i]; j++){
			s += ch[i];
		}
	}
	int l = s.size(), cnt = 0;
	for(int i = 0; i <= l/2; i++){
		if(s[i] != s[l-i-1]){
			cnt++;
		} 
	}
	cout << cnt;
	return 0;
}
