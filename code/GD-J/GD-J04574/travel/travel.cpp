#include <bits/stdc++.h>
using namespace std;

string c_1, c_2, s_1, s_2;
int a_1, b_1, a_2, b_2;

int f(char a, char b){
	if(a >= b) swap(a, b);
	if((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'E')){
		return 2;
	}
	else if(a == 'A' && b == 'C') return 1;
	else return 0;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	a_1 = (c_1[0] - '0') * 10 + c_1[1] - '0';
	a_2 = (c_2[0] - '0') * 10 + c_2[1] - '0';
	b_1 = (s_1[0] - '0') * 10 + s_1[1] - '0';
	b_2 = (s_2[0] - '0') * 10 + s_2[1] - '0';
	if(a_1 == a_2){
		cout << 1;
	}
	else cout << 0;
	if(a_1 == a_2 && b_1 == b_2) cout << 1;
	else cout << 0;
	if(a_1 == a_2 && b_1 == b_2 && (f(s_1[2], s_2[2]) >= 1)) cout << 1;
	else cout << 0;
	if(a_1 == a_2 && b_1 == b_2 && (f(s_1[2], s_2[2]) == 2)) cout << 1;
	else cout << 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
