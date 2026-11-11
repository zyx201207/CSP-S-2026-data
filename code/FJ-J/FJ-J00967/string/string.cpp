//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int n;
string s = "";
int a[200005];
char c[200005];
long long ans;
void check(){
	int k = s.length()-1;
	for(int i = 0;i <= k;i++){
		if(s[i] != s[k-i]){
			ans++;
		}
	}
	ans/=2;
	return;	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++){
			s+=c[i];
		}
	}
	check();
	cout << ans;
	return 0;
}

