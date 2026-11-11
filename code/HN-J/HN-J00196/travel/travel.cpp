#include <bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << '1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout << '1';
			if(s1 > s2){
				swap(s1,s2);
			}
			if(s1[2]=='A'){
				if(s2[2]=='B')cout << "11";
				else if(s2[2]=='C')cout << "10";
				else cout << "00";
			}
			else if(s1[2]=='B'){
				if(s2[2]=='C')cout << "11";
				else cout << "00";
			}
			else if(s1[2]=='C')cout << "00";
			else cout << "11";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
