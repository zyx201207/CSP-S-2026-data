#include<iostream>
using namespace std;
int main(){
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool o1 , o2 , o3 , o4;
	o1 = o2 = o3 = o4 = false;
	if(c1 == c2) o1 = true;
	if(o1 && s1[0] == s2[0] && s1[1] == s2[1]) o2 = true;
	if(o1 && o2 && (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' ||
	s1[2] >= 'D' && s2[2] >= 'D')) o3 = true;
	string S1;S1 += s1[0];S1 += s1[1];
	string S2;S2 += s2[0];S2 += s2[1];
	if(o1 && o3 && !(s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A')) o4 = true;
	cout << o1 << o2 << o3 << o4 << '\n';
	return 0;
} 
