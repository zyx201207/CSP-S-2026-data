#include<iostream>
using namespace std;
int abs1(int n){
	if(n < 0)return -n;
	else return n;
}
int main(){
		freopen("travel.in", "r", stdin);
		freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4, s = "0000";
	cin>>s1 >> s2 >> s3 >> s4;
	if(s1 == s3)s[0] = '1';
	if(s2[0] == s4[0] && s2[1] == s4[1] && s[0] == '1')s[1] = '1';
	if(s[1] == '1'){
		bool f = s2[2] > 'C';
		bool f1 = s4[2] > 'C';
		if(f == f1)s[2] = '1';
	}
	if(s2[2] == 'C' && s4[2] == 'D')s[3] = '0';
	else{
		if(abs1 (s2[2] - s4[2]) == 1 && s[2] == '1') s[3] = '1';
	}
	cout << s << endl;
	return 0;
}
