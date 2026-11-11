#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char l1=s1[0]+s1[1],l2=s2[0]+s2[1],z1=s1[2],z2=s2[2];
	if(c1==c2){
		cout << "1";
		if(l1==l2){
			cout << "1";
			if((z1<'D' && z2<'D') || (z1>'C' && z2>'C')){
				cout << "1";
				if((z1=='C' && z2=='D') || (z1=='D' && z2=='C')){
					cout << "00";
					return 0;
				}else if(abs(z1-z2)==1){
					cout << "1";
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	
	return 0;
} 
