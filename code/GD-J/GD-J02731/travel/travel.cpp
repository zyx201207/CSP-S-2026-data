#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1=(c1[0]-'0')*10+(c1[1]-'0');
	int a2=(c2[0]-'0')*10+(c2[1]-'0');
	int b1=(s1[0]-'0')*10+(s1[1]-'0');
	int b2=(s2[0]-'0')*10+(s2[1]-'0');
	int d1=s1[2]-'A',d2=s2[2]-'A';
	if (d1==3)
		d1=5;
	else if (d1==5)
		d1=6;
	if (d2==3)
		d2=5;
	else if (d2==5)
		d2=6;
	if (a1==a2){
		cout << 1;
		if (b1==b2){
			cout << 1;
			if (abs(d1-d2)<=2){
				cout << 1;
				if (abs(d1-d2)<=1)
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
