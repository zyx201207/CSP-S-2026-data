#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int chx1 = (c1[0]-'0')*10+c1[1]-'0';
	int chx2 = (c2[0]-'0')*10+c2[1]-'0';
	int x1 = s1[2]-'A',y1 = (s1[0]-'0')*10+s1[1]-'0',x2 = s2[2]-'A',y2 = (s2[0]-'0')*10+s2[1]-'0';
	if(s1[2] == 'F')x1--;
	if(s2[2] == 'F')x2--;
	bool xf1 = (x1 <= 2);
	bool xf2 = (x2 <= 2);
	if(chx1 == chx2){
		cout << 1;
		if(y1 == y2){
			cout << 1;
			if(xf1 == xf2){
				cout << 1;
				if(abs(x1-x2) == 1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
		
	}else{
		cout <<"0000";
	}
	return 0;
}