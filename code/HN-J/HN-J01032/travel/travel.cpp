#include <bits/stdc++.h>
using namespace std;
bool abc(string s){
	return s[2] == 'A'||s[2] == 'B'||s[2] == 'C';
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<'0000';
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<'1000';
	else if(abc(s1)!=abc(s2))cout<<'1100';
	else if(abs(s1[2]-s2[2])!=1)cout<<'1110';
	else cout<<'1111';
	return 0;
}
