#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string s = "";
string back(string s){
	string s1;
	for(int i = s.size();i >= 0;i --){
		s1 += s[i];
	}
	s1 = s1.substr(1, s1.size() - 1);
	return s1;
}
bool hwc(string s){
	string s1;
	for(int i = s.size();i >= 0;i --){
		s1 += s[i];
	}
	s1 = s1.substr(1, s1.size() - 1);
	if(s1 == s) return 1;
	else return 0;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		int c;
		char a;
		cin >> c >> a;
		for(int j = 1;j <= c;j ++) s += a;
	}
	if(hwc(s)){
		cout << 0;
		return 0;
	}
	int sum = s.size();
	if(sum % 2 == 1){
		int mid = sum / 2;
		string s1 = back(s.substr(0, mid));
		for(int i = mid + 1;i < sum;i ++){
			if(s[i] != s1[i - mid]) cnt ++;
		}
		cout << cnt;
	}
	else{
		int mid = sum / 2;
		int m1 = mid - 1;
		if(s[mid] != s[m1]) cnt = 1;
		string s1 = back(s.substr(0, m1));
		for(int i = mid + 1;i < sum;i ++){
			if(s[i] != s1[i - mid]) cnt ++;
		}
		cout << cnt;
	}
	
	return 0;
} 
