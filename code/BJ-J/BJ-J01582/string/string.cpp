#include<bits/stdc++.h>
using namespace std;
string s, x;
int a, n, ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out:, "w", stdout);
	cin >> n;
	while(n--){
		cin >> a >> x;
		while(a--){
			s += x;
		}
	}
	for(int i = (s.size() + 1 ) / 2, j = i - 1; i < s.size(); i++, j--){
		if(s[i] != s[j]){
			ans++;
		}
	} 
	cout << ans;
	return 0;
}
