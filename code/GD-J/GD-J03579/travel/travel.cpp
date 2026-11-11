#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string str1, str2, str3, str4;
bool check(string s1, string s2){
	if(s1[0] <= 'C' && s2[0] <= 'C') return true;
	if(s1[0] >= 'D' && s2[0] >= 'D') return true;
	return false;
}
bool check2(){
	if((int)(abs(str2[0] - str4[0])) == 1) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	str1 = s1.substr(0, 2); 
	str2 = s1.substr(2, 1);
	str3 = s2.substr(0, 2);
	str4 = s2.substr(2, 1);
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && str1 == str3) cout << 1;
	else cout << 0;
	if(c1 == c2 && str1 == str3 && check(str2, str4)) cout << 1;
	else cout << 0; 
	if(c1 == c2 && str1 == str3 && check(str2, str4) && check2()) cout << 1;
	else cout << 0;
	return 0;
} 
