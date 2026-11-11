#include <bits/stdc++.h>

using namespace std;

string c1,c2,a,b;
string s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0); 
	
	cin >> c1 >> a >> c2 >> b;
	for(int i = 0;i < 3;i++){
		s1[i] = a[i];
		s2[i] = b[i];
	}
	bool flag1 = 1;
	if(c1 == c2)
		cout << 1;
	else{
		cout << 0;flag1 = 0;
	}
	
	string str1 = s1[0] + s1[1],str2 = s2[0] + s2[1];
	string chr1 = s1[2],chr2 = s2[2];
	
	if(str1 == str2 and flag1)
		cout << 1;
	else
		cout << 0;
	
	if(flag1 and str1 == str2 and (chr1 >= "A" and chr1 <= "C" and "A" <= chr2 and chr2 <= "C") or ((chr1 == "D" or chr1 == "F" )and (chr2 == "D" or chr2 == "F")))
		cout << 1;
	else
		cout << 0;
	
	if(str1 == str2 and abs(char(chr1[0]) - char(chr2[0])) == 1 and (chr1 >= "A" and chr1 <= "C" and "A" <= chr2 and chr2 <= "C") or ((chr1 == "D" or chr1 == "F" )and (chr2 == "D" or chr2 == "F")))
		cout << 1;
	else
		cout << 0;
		
	return 0;
} 
