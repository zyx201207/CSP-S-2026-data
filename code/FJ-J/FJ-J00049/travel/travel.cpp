#include <bits/stdc++.h>
using namespace std;

string c1, c2;
string s1, s2;
int p1, p2;

//c ³µÏá 
//p ÅÅ 

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	p1 = 10 * (s1[0] - '0') + (s1[1] - '0');
	p2 = 10 * (s2[0] - '0') + (s2[1] - '0');
	//cout << p1 << " " << p2 << "\n";
	
	if(c1 == c2){
		cout << "1";
		if(p1 == p2){
			cout << "1";
			if( (s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C') ){
				//cout << s1[2] << " " << s2[2] << "\n";
				cout << "1";
				
				bool a = ( (s1[2] + 1 == s2[2]) || (s1[2] - 1 == s2[2]) );
				//bool b = ( (s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C') );
				
				if(a)cout << "1";
				else cout << "0"; 
			}else cout << "00";
		}else cout << "000";
	}else{
		cout << "0000";
	}
	
	return 0;
} 
