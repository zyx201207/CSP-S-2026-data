#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2){
		cout << 1;
	}
	else {
		cout << 0;
	}
	
	bool flag1 = false;
	for (int i = 0; i < 2; i++){
		if (s1[i] == s2[i]){
			flag1 = true;
		}
	}
	if (flag1 == true){
		cout << 1;
	}
	else {
		cout << 0;
	}
	
	bool flag2 = false;
	if (s1[2] >= 65 && s1[2] <= 67 && s2[2] >= 65 && s2[2] <= 67){
		flag2 = true;
	}
	else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
		flag2 = true;
	}
	if (flag1 == true && flag2 == true){
		cout << 1;
	}
	else {
		cout << 0;
	}
	
	if (s1[2] >= 65 && s1[2] <= 67){
		if (s1[2]-s2[2] == 1 || s2[2]-s1[2] == 1){
			cout << 1;
		}
		else {
			cout << 0;
		}
	else if ((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
		cout << 1;
	}
	else {
		cout << 0;
	}
	
	return 0;
	
}
