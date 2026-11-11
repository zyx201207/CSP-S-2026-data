#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);/////////////////////////////////////////////若要测试，请务必注释freopen 
	freopen("string.out","w",stdout);///////////////////////////////////////////测试结束，请务必打开freopen 
	int n;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j = 1;j <= x;j++){
			s += c;
		}
	}
	int sum = 0;
	int l = 0,r = s.length()-1;
	while(l < r){
		if(s[l] != s[r]) sum++;
		l++,r--;
	}
	cout << sum;
	return 0;
}
