#include<bits/stdc++.h>
using namespace std;
#define int long long
string n1, n2, s1, s2;
bool flag, flag1;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> s1 >> n1 >> s2 >> n2;
	
	if(s1 != s2){
		cout << "0000";
		return 0; 
	}
	else cout << "1";
	
	for(int i = 1; i < 2; i++){
		if(n1[i] != n2[i]){
			flag = 1;
		}
	}
	if(flag){
		 cout << "000";
		 return 0;
	}
	else cout << 1;
	if(n1[2] == 'D' || n1[2] == 'F'){
		if(n2[2] < 'D')flag1 = 1;
	}
	if(n2[2] == 'D' || n2[2] == 'F'){
		if(n1[2] < 'D')flag1 = 1;
	}
	if(flag1){
		cout << "00";
		return 0;
	} 
	else cout << "1";
	
	if(n1[2] - n2[2] == 1 || n2[2] - n1[2] == 1){
		cout << "1";
	}else cout << "0";
	return 0;
} 
