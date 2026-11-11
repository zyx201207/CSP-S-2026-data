#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1[5],s1[5],c2[5],s2[5];
	for(int i=0; i<5; i++){
		cin >> c1[i] >> s1[i] >> c2[i] >> s2[i];
	}
	if(c1 == c2){
		cout << 1;
	}
	else {
		cout << 0;
	}
	if(s1[0][1] == s2[0][1]){
		cout << 1;
	}
	else {
		cout << 0;
	}
	if(s1[2] <= "C" && s2[2] <= "C"){
		cout << 1;
	}
	else if(s1[2] > "C" && s2[2] > "C"){
		cout << 1;
	}
	else {
		cout << 0;
	}
	if(s1[2] == s2[2]+"1"){
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}
