#include<bits/stdc++.h>
using namespace std;
bool check(char l,char r){
	if(l=='A' && r=='B' || l=='A' && r=='C' || l=='B' && r=='C' || l=='B' && r=='A' || l=='C' && r=='B' || l=='C' && r=='A' || l=='D' && r=='E' || l=='E' && r=='D'){
		return true;
	}
	else{
		return false;
	}
}
bool jc(char n,char m){
	if(n=='A' && m=='B' || n=='B' && m=='A' || n=='B' && m=='C' || n=='C' && m=='B' || n=='D' && m=='E' || n=='E' && m=='D'){
		return true;
	}
	else{
		return false;
	}
}
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin >> a >> x >> b >> y;
	if(a==b){
		cout << "1";
		if(x[0]==y[0] && x[1]==y[1]){
			cout << "1";
			if(check(x[2],y[2])){
				cout << "1";
				if(jc(x[2],y[2])){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
