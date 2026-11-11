#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool q = false;
	if(c1 == c2){
		q = true;
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	bool b = false;
	if(q == true and s1[0] == s2[0] and s1[1] == s2[1]){
		b = true;
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	bool c = false;
	if(b == true and (s1[2] == 'D' and s2[2] == 'F') 
	or (s1[2] == 'A' and s2[2] != 'D' and s2[2] != 'F') 
	or (s1[2] == 'B' and s2[2] != 'D' and s2[2] != 'F') 
	or (s1[2] == 'C' and s2[2] != 'D' and s2[2] != 'F') 
	or (s1[2] == 'F' and s2[2] == 'D')){
		c = true;
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(c == true and abs(s1[2] - s2[2]) == 1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
