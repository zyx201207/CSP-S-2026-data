#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
char c,d;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = (s1[0]-'0')*10+(s1[1]-'0');
	b = (s2[0]-'0')*10+(s2[1]-'0');
	c = s1[2];
	d = s2[2];
	if(c1 == c2){
		cout << "1";
		if(a == b){
			cout << "1";
			if(((c == 'D' || c == 'F') && 'A' <= d <= 'C') || ((d == 'D' || d == 'F') && 'A' <= c <= 'C'))
			{
				cout << "00";
			}
			else{
				cout << "1";
				if((c+'0' == d+'1') || (c+'1' == d+'0')){
					cout << "1";
				}
				else{
					cout << "0";
				}
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
