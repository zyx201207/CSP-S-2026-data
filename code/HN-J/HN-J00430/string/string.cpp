#include<bits/stdc++.h>
using namespace std;

int n; string s="0"; long long len;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		int num; char c;
		cin >> num >> c;
		for(int i=1; i<=num; i++){
			s += c;
			len++;
		}
	}
	
	int cnt=0;
	for(int i=1; i<=len/2; i++){
		if(s[i] != s[len+1-i]) cnt++;
	}
	
	cout << cnt;
	
	
	return 0;
}
