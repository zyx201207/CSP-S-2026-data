#include<bits/stdc++.h>
using namespace std;
string str;
int n, cnt=0;
bool is_sth(string s){
	string s2="";
	for(int i=s.size()-1; i>=0; i--){
		s2+=s[i];
	}
	return s2==s;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		int a;
		char m;
		cin >> a >> m;
		for(int j=1; j<=a; j++)
			str+=m;
	}
	if(is_sth(str)) cout << 0;
	else{
		string a=str.substr(0, str.size()/2);
		for(int i=(str.size()+1)/2; i<str.size(); i++){
			if(str[i] != a[i]){
				cnt++;
				str[i]=a[i];
			}
		}
		cout << cnt;
	}
	return 0;
}
