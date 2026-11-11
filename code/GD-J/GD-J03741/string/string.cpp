#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		char now;
		cin >> x >> now;
		for(int j = 1;j <= x;j++){
			s += now;
		}
	}
	long long cnt = 0;
	for(int i = 0;i < s.size() / 2;i++){
		if(s[i] != s[s.size() - i - 1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
