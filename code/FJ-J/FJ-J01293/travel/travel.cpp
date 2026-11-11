#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1==b1) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	int a3=int(a2[0]-'0')*10+int(a2[1]-'0');
	int b3=int(b2[0]-'0')*10+int(b2[1]-'0');
	if(a3==b3){
		cout << 1;
	} 
	else{
		cout << "000";
		return 0;
	}
	int a4=int(a2[2]-'A'+1);
	int b4=int(b2[2]-'A'+1);
	if((a4<=3&&b4<=3)||(a4>3&&b4>3)) cout << 1;
	else{
		cout << "00";
		return 0;
	} 
	if(abs(a4-b4)==1) cout << 1;
	else cout << 0;
	return 0;
}
