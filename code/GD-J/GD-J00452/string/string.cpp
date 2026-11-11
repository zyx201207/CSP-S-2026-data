#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i = 0; i < n; ++i){
		long long h;
		char c;
		cin >> h >> c;
		for(long long j = 0; j < h; ++j){
			s += c;
		}
	}
	long long ans = 0;
	for(long long i = 0, j = s.size(); i < s.size()/2+1, j >= s.size()/2-1; ++i,--j){
		if(s[i] != s[j]){
			s[i] = s[j];
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
