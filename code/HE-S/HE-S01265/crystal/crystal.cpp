#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("crystal.in","r",std.in);
	freopen("crystal.out","w",std.out); 
	struct crystal(){
		int n;
		int m;
	};
	int cnt=0;
	crystal s[100];
	for(int i=1;i<=n;i++){
		cin >> s.n[i] >> s.m[i];
	}
	for(int j=1;j<=m;j++){
		s.n[i]++;
		if(s.n[i]==s.n[i+1]){
			cnt++;
		}
	}
	cout << cnt; 
	return 0;} 
