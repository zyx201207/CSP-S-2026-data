#include<bits/stdc++.h>
using namespace std;

int n;
string s;
long long ans = 0;
long long l = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i = 1 ; i <= n; i++){
		long long x;
		char c;
		cin >>x >>c;
		for(int j = 1;j <= x ; j++){
			s += c;
		}
		l += x;
	}
	for(int i = 0 ; i <= l / 2 - 1; i++){
		if(s[i] == s[l - i - 1]){
			continue;
		}
		else{
			ans++;
		}
	}
	cout <<ans <<endl;
	return 0;
}
