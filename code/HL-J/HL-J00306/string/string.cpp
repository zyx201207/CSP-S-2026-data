#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int main(){
	freopen("string.in", "r",stdin);
	freopen("string.out", "w",stdout);
	int n;
	int num;
	string f;
	int length = 0;
	string s;
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> num;
		cin >> f;
		for(int j = 0;j < num; i++){
			s += f;
			length++;
		}
	}
	for(int i = 1;i <= length; i++){
		int l = length;
		if(s[i] != s[l-1]){
			cnt++;
		}
		l--;
	}
	cout << cnt;
	return 0; 
}