#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
bool check_sit1() {
	string s1=b;
	s1=s1.substr(0,2);
	string s2=d;
	s2=s2.substr(0,2);

	if(s1==s2) return 1;
	return 0;
}
bool same_way(char s1,char s2) {
	if(s1>='A'&&s1<='C'&&s2>='A'&&s2<='C') return 1;
	if((s1=='F'||s1=='D')&&(s2=='F'||s2=='D')) return 1;
	return 0;
}
bool check_sit2() {
	char s1=b[2];
	char s2=d[2];

	if(same_way(s1,s2)) return 1;
	return 0;
}
int to_num(string s) {
	int sum=0;
	for(int i=0;i<s.size();i++) {
		sum=sum*10+(s[i]-'0');
	}
	return sum;
}
bool near_test(string s1,string s2) {
	string sub1=s1;
	sub1=sub1.substr(0,2);
	string sub2=s2;
	sub2=sub2.substr(0,2);
	
	int num1,num2;
	num1=to_num(sub1);
	num2=to_num(sub2);
	if(num1==num2) {
		if(s1[2]!='D'||s1[2]!='F') {
			if(s1[2]=='C'&&s2[2]=='D') return 0;
			if(s1[2]-1==s2[2]) return 1;
			if(s1[2]+1==s2[2]) return 1; 
		}else {
			if(s1[2]=='D'&&(s2[2]=='F'||s2[2]=='C')) return 1;
			if(s1[2]=='F'&&s2[2]=='D') return 1;
		}
	}else if(s1[2]==s2[2]) {
		if(num1-1==num2) return 1;
		if(num1+1==num2) return 1;
	}
	return 0;
}
bool check_ne_sit() {
	string s1=b;
	string s2=d;
	if(near_test(s1,s2)) return 1;
	return 0;
}
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a==c) cout << 1;
	else cout << 0;
	if(a==c&&check_sit1()) cout << 1;
	else cout << 0;
	if(a==c&&check_sit2()&&check_sit1()) cout << 1;
	else cout << 0;
	if(a==c&&check_ne_sit()) cout << 1;
	else cout << 0; 
return 0;
} 
