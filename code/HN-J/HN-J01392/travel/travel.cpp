#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
void check(string c1,string s1,string c2,string s2){
 	bool a = (c1 == c2? 1:0);
 	bool b = (s1[0] == s2[0] && s1[1] == s2[1] && a? 1:0);
 	bool c = ((s1[2] <= 'C' && s2[2] <= 'C' || s1[2] > 'C' && s2[2] > 'C') && b? 1:0); 
	bool d = ((s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]) && c? 1:0);
	cout << a << b << c << d;
 }
 int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
 	cin >> c1 >> s1 >> c2 >> s2;
 	check(c1,s1,c2,s2);
 	return 0;
 }
