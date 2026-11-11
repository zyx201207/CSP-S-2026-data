#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	for(int i = 1 ; i <= n ; i ++){
		int len;
		cin >> len;
		char c;
		cin >> c;
		for(int j = 1 ; j <= len ; j ++) s += c;
	}
	int m = s.size();
	int cnt = 0;
	int i = 0 , j = m - 1;
	while(i < j){
		if(s[i] != s[j]){
			cnt ++;
		}
		i ++ , j --;
	}
	cout << cnt << '\n';
	return 0;
}
/*
3
 2 a
 2 b
 1 c
2
 2 a
 3 a
*/
