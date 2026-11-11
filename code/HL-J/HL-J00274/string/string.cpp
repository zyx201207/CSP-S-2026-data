#include <bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	if(n == 1){
		cout << "0";
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++)
			s+=c[i];
	}
	string ss;
	for(int i = s.size(); i>= 0; i--){
		ss+=s[i];
	}
	if(s == ss){
		cout << "0";
		return 0;
	}
	
	if(n <= 2)
	return 0;
}
