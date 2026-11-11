#include<bits/stdc++.h>

using namespace std;
int n;
long long x;
char c;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while(n--){
		cin >> x >> c;
		while(x--)s+=c;
	}
	long long ans = 0;
	for(int i = 0; i <= s.size()/2; i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}