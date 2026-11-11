#include <bits/stdc++.h>
using namespace std;

struct node{
	int sum;
	char c;
}a[200010]; 

bool isBack(string s){
	for(int i = 0; i <= s.size() / 2; i++){
		if(s[i] != s[s.size() - i - 1]){
			return 0;
		}
	} 
	return 1;
}

int makeBack(string s){
	int ans = 0;
	for(int i = 0; i <= s.size() / 2; i++){
		if(s[i] != s[s.size() - i - 1]){
			ans++;
		}
	} 
	return ans;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++){
		cin >> a[i].sum >> a[i].c;
		for(int j = 1; j <= a[i].sum; j++){
			s += string(1, a[i].c);
		}
	}
	if(isBack(s)){
		cout << 0;
	}
	else{
		cout << makeBack(s);
	}
	return 0;
} 

