#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j = 0;j < x;j++){
			s += c;
		}
	}
	int cnt = 0;
	int l = s.size();
	for(int i = 0;i < l / 2;i++){
		if(s[i] != s[l - i - 1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
