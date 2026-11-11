#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 10;
string c1 , s1 , c2 , s2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	int a = (s1[0] - '0') * 10 + (s1[1] - '0');
	int b = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(a == b){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	int c = (s1[2] - 'A');
	int d = (s2[2] - 'A');
	if((c <= 2 && d <= 2) || (c > 2 && d > 2)){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if(abs(c - d) == 1){
		cout << "1";
	}else{
		cout << "0";
		return 0;
	}
	return 0;
}
