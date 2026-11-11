#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,tmp,ans = 0;
	string s,c;
	cin >> n;
	while(n--){
		cin >> tmp >> c;
		while(tmp){
			s += c;
			tmp--;
		}
	}
	long long len = s.size();
	for(int i = 0;i < len / 2;i++){
		if(s[i] != s[len - i - 1]){
			s[len - i - 1] = s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
