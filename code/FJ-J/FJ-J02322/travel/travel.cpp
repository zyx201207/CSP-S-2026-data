#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
string c1,c2,s1,s2;
bool tc(void){
	if(s1[2] <= 'C' && s2[2] <= 'C')
		return true;
	if(s1[2] >= 'D' && s2[2] >= 'D')
		return true;
	return false;
}
bool next(void){
	if(int(s1[2] - 'A') + int(s2[2] - 'A') == 8)
		return true;
	if(abs(int(s1[2] - s2[2])) == 1)
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if(tc()){
				cout << 1;
				if(next())
					cout << 1;
				else
					cout << 0;
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else
		cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
