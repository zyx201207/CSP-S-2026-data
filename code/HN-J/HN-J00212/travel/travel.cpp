#include<bits/stdc++.h>
using namespace std;
string s1, s2;
char se1, se2;
int x, y, n1, n2;
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> s1 >> y >> s2;
	se1 = s1[2]; 
	se2 = s2[2];
	n1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	n2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(x != y){
		cout << "0000";
		return 0;
	}else cout << "1";
	if(n1 == n2){
		cout <<  "1";
	}else{
		cout << "000";
		return 0;
	}
	if((se1 == 'D' && se2 == 'F') || (se1 == 'F' && se2 == 'D')){
		cout << "11";
		return 0;
	}
	if(abs(se1 - se2) == 1){
		if (!((se1 == 'C' && se2 == 'D') || (se2 == 'C' && se1 == 'D'))) cout << "11";
		else{
			cout << "00";
			return 0;
		}
	}else if(abs(se1 - se2) == 1 || ((se1 == 'C' && se2 == 'A') || (se1 == 'A' && se2 == 'C'))){
		cout << "10";
	}else{
		cout << "0";
	}
	return 0;
} 

