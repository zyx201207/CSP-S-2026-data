#include <bits/stdc++.h>
using namespace std;
int n;
string s,ss;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		int num;
		char z;
		cin >> num >> z;
		while(num --){
			s += z;
		}
	}
	for(int i = s.size() -1; i >= 0 ; i --){
		ss+=s[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		if(ss[i] != s[i]) cnt ++;
	}
	cout << cnt;
	return 0;
}
