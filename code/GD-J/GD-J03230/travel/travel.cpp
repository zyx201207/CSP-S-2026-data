#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'

string c1,c2,s1,s2;
bool check1(char x , char y){
	return ((x <= 'C' && y <= 'C') || ('D' <= x && x <= 'F' && 'D' <= y && y <= 'F'));
} 
bool check2(char x , char y){
	return ((x <= 'C') ? abs(int (x - y)) == 1 : ((x == 'D' && y == 'F') || (x == 'F' && y == 'D')));
}
void solve(){
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if (check1(s1[2] , s2[2])){
				cout << "1" ;
				if (check2(s1[2] , s2[2])){
					cout << "1" << endl;
				}else{
					cout << "0" << endl;
				}
			}else{
				cout << "00" << endl;
			}
		}else{
			cout << "000" << endl;
		}
	}else{
		cout << "0000" << endl;
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

