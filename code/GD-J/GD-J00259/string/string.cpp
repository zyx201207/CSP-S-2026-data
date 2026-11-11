#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[30];
string s="";


string is_hw(string s){
	string s1="";
	for(int i=s.size()-1;i>=0;i--){
		s1 += s[i];
	}
	return s1;
}
void solve(){
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin >> x >> y;
		for(int j=1;j<=x;j++){
			s += y;
		}
	}
	string s1 = is_hw(s);
	long long cnt = 0;
	if(s1 == s){
		cout << 0;
	}else{
		for(int i=0;i<s.size();i++){
			if(s[i] != s1[i]){
				cnt++;
			}
		}
		cnt /= 2;
		cout << cnt;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	solve();
	return 0;
}
