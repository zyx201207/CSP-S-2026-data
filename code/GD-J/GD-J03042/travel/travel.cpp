#include <bits/stdc++.h>
using namespace std;

bool bside(char x){
	if(x-'A'<=2) return 1;
	return 0;
}

int main(){
	freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

	string C1, C2;
	string s1, s2; cin >> C1 >> s1 >> C2 >> s2;
	int pai1, pai2;
	pai1= (s1[0]-'0')*10 + (s1[1]-'0');
	pai2= (s2[0]-'0')*10 + (s2[1]-'0');
	int c1= (C1[0]-'0')*10 + (C1[1]-'0');
	int c2= (C2[0]-'0')*10 + (C2[1]-'0');
	
	if(c1==c2){
		cout << 1;
	}
	else{
		cout << 0; cout << 0; cout << 0; cout << 0;
		return 0;
	}

	if(pai1==pai2){
		cout << 1;
	}
	else{
		cout << 0; cout << 0; cout << 0;
		return 0;
	}

	if( (bside(s1[2]) && bside(s2[2])) || (!bside(s1[2]) && !bside(s2[2])) ){
		cout << 1;
	}
	else{
		cout << 0; cout << 0;
		return 0;
	}

	if((s1[2]==s2[2]-1) || (s1[2]==s2[2]+1)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
