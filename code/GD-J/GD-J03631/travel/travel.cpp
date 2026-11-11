#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
string p = "ABC", pp = "DF";
bool f1 = false, f2 = false, pf = false;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << 1;
		f1 = true;
	}else{
		cout << "000";
		return 0;
	}
	if(f1){
		if(((p.find(s1[2]) != string::npos) && (p.find(s2[2]) != string::npos)) || 
		((pp.find(s1[2]) != string::npos) && (pp.find(s2[2]) != string::npos))){
			f2 = true; 
			cout << 1;
		}else{
			cout << "00";
			return 0;
		}
	}
	if(f2){
		char k1 = s1[2] + 1, k2 = s1[2] - 1;
		if(s1[2] == 'C') k1 = '!';
		if(s1[2] == 'D') k2 = '!';
		if(k1 == s2[2] || k2 == s2[2]){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}
