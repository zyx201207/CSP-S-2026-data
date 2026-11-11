#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	int n,id = 1;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c; 
		for(int j = 1;j <= a;j++){
			s += c;
			id++;
		}
	}
	int l = 1,r = id;
	while(l <= r){
		if(s[l] != s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout <<ans;
	return 0;
}
