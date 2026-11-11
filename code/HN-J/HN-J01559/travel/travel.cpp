#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 + 'A' == c2 + 'A'){
		cout << 1;
	}
	if(c1 + 'A' != c2 + 'A'){
		cout << 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2){
		cout << 1;
	}
	else{
			cout << 0;
			cout << 0;
	}
	if(s1[2] + 1 == 66 && s2[2] + 1 == 67 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 1; 
	}
	else if(s1[2] + 1 == 67 && s2[2] + 1 == 66 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 1;
	}
	else if(s1[2] + 1 == 66 && s2[2] + 1 == 68 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 0;
	}
	else if(s1[2] + 1 == 67 && s2[2] + 1 == 68 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 1;
	}
	else if(s1[2] + 1 == 68 && s2[2] + 1 == 67 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 1;
	}
	else if(s1[2] + 1 == 68 && s2[2] + 1 == 66 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 0;
	}
	else if(s1[2] + 1 == 69 && s2[2] + 1 == 71 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 1;
	}
	else if(s1[2] + 1 == 71 && s2[2] + 1 == 69 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 1;
		cout << 1;
	}
	else if(s1[2] + 1 == 68 && s2[2] + 1 == 69 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 0;
		cout << 0;
	}
	else if(s1[2] + 1 == 69 && s2[2] + 1 == 68 && c1 + 'A' == c2 + 'A' && s1[1] == s2[1] && s1[0] == s2[0]){
		cout << 0;
		cout << 0;
	}
	else{
		cout << 0;
	}
	return 0;
}
