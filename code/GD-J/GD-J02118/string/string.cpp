#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, M = 5e5 + 5;
int n;
ll cnt;
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 0;j < a;j++) s += c;
	}
	ll len = s.size();
	int i = len / 2;
	if(len % 2) i++;
	for(;i < len;i++){
		if(s[i] != s[len - i - 1]) cnt++;
	}
	cout << cnt;
	return 0;
}
