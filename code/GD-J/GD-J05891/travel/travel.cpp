#include <bits/stdc++.h>
using namespace std;
string s1, s3;
char s2[4], s4[4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1;
	for(int i = 1; i <= 3; i ++){
		cin >> s2[i];
	}
	cin >> s3;
	for(int i = 1; i <= 3; i ++){
		cin >> s4[i];
	}
	if(s1 == s3){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	if(s2[1] == s4[1] && s2[2] == s4[2]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if((s2[3] < 'D' && s4[3] < 'D') || (s2[3] > 'C' && s4[3] > 'C')){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	int check1 = s2[3], check2 = s4[3];
	if((check1 + 1 == check2) || (check2 + 1 == check1)){
		cout << 1;
		return 0;
	}
	else{
		cout << 0;
		return 0;
	}
	return 0;
}

