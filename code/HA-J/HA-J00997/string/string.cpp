#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s="";
	for(int i = 1; i <= n; ++i){
		int num;
		char ch;
		cin >> num >> ch;
		while(num--){
			s+=ch;
		}
	}
	int len = s.size();
	int cnt = 0;
	for(int i = 0; i <= len / 2; ++i){
		if(s[i] != s[len-i-1]){
			s[len-i-1] = s[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}