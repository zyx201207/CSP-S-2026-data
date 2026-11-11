#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,r;
	string x1,r1;
	cin >> r >> r1 >> x >> x1;
	if(r==x){
		string x2=" "+x1[0],r2=" "+r1[0];
		x2+=x1[1];
		r2+=r1[1];
		if(x2==r2){
			char x3=x1[2],r3=r1[2];
			if((x3=='D'&&r3=='F')||(x3=='F'&&r3=='D')){
				cout << "1111";
			}
			else if((x3>='A'&&x3<='C')&&(r3>='A'&&r3<='C')){
				if(x3=='B'||r3=='B'){
					cout << "1111";
				}
				else{
					cout << "1110";
				}
			}
			else{
				cout << "1100";
			}
		}
		else{
			cout << "1000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
