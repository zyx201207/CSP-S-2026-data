#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	s = " "+s;
	int n;
	cin >> n;
	while(n--){
		long long ra;
		cin >> ra;
		char rc;
		cin >> rc;
		for(long long i = 1; i <= ra; i++){
			s = s+rc;
		}
	}
	long long l=1, r = s.size()-1, ans=0;
	while(l < r){
		if(s[l] != s[r]){
			ans++;
		}
		l++, r--;
	}
	cout << ans;
	return 0;
}
