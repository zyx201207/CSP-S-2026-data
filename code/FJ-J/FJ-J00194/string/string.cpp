//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,s_len,cnt=0;
	string s="";
	char c;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a >>c;
		while(a--) s+=c;
	}
	s_len = s.size();
	for(int i=0;i<s_len/2;i++){
		
		if(s[i] != s[s.size()-i-1]) cnt++;
	}
	cout << cnt;
	return 0;
}
