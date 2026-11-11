#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1 , s1 , c2 , s2;
int num(string s){
	int k = 0;
	for(int i = 0;i < s.size();i++)
		if( s[i] >= '0' && s[i] <= '9' ) k = k*10 + s[i] - '0';
		else break;
	return k;
}
int t(string s){
	return ( s[2] == 'A' || s[2] == 'B' || s[2] == 'C' );
}
int tt(string s){
	if( s[2] == 'F' ) s[2] = 'E';
	return s[2] - 'A';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	cout << int(c1 == c2);
	cout << int(c1 == c2 && num(s1) == num(s2));
	cout << int(c1 == c2 && num(s1) == num(s2) && t(s1) == t(s2) );
	cout << int(c1 == c2 && num(s1) == num(s2) && t(s1) == t(s2) && abs(tt(s1)-tt(s2)) == 1 );
	return 0;
}
/*
04 03C 05 03D
ans : 0000 
04 03C 04 03D
ans : 1100
*/
