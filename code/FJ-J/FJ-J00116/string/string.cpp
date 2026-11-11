#include<bits/stdc++.h>
#define int long long
using namespace std;
int minn(string s){
	string new_str;
	int cnt = 0;
	for (int i = s.size() - 1; i >= 0 ;i --) new_str+=s[i];
	for (int i = 0 ;i < s.size(); i ++){
		if (s[i] != new_str[i]) cnt ++;
	}
	return cnt/2;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string str;
	for (int i = 1; i <= n; i ++){
		int x; cin >> x;
		char ch; cin >> ch;
		for (int i = 1; i <= x; i ++){
			str+=ch;
		} 
	} 
	cout << minn(str) << endl; 
	return 0;

}


