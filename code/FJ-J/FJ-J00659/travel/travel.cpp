#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool judge1(char a,char b){
	if(a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C')
		return true;
	if(a >= 'D' && a <= 'E' && b >= 'D' && b <= 'E')
		return true;
	else
		return false;
}

bool judge2(char a,char b){
	if(a == 'A' && b == 'B')
		return true;
	else if(a == 'B' && (b == 'A' || b == 'C'))
		return true;
	else if(a == 'C' && b == 'B')
		return true;
	else if(a == 'D' && b == 'E')
		return true;
	else if(a == 'E' && b == 'D')
		return true;
	else 
		return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if(judge1(s1[2],s2[2])){
				cout << 1;
				if(judge2(s1[2],s2[2]))
					cout << 1;
				else
					cout << 0;
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	
	return 0;
}
