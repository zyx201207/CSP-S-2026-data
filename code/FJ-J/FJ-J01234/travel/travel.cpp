#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	string t1, t2; 
	for(int i = 0; i <= 1; i++){
		t1 += s1[i];
	}
	for(int i = 0; i <= 1; i++){
		t2 += s2[i];
	}
	if(t1 == t2){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	char cc1 = s1[2];
	char cc2 = s2[2];
	if(cc1 <= 'C' && cc2 <= 'C' || cc1 > 'C' && cc2 > 'C'){
		cout << '1';
	}else{
		cout << "00";
		return 0;
	}
	if(cc1 > cc2){
		swap(cc1, cc2);
	}
	if(cc2 == cc1 + 1 || cc2 == 'F' && cc1 == 'D'){
		cout << '1'; 
	}else{
		cout << 0;
	}
	return 0;
}
