#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c3;
string c2,c4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1==c3){
		cout << 1;
		int x=((c2[0]-'0')*10+c2[1]-'0');
		int y=((c4[0]-'0')*10+c4[1]-'0');
		if(x==y){
			cout << 1;
			if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C'&&c2[2]<='F'&&c4[2]<='F')){
				cout << 1;
				int a=c2[2]-'A',b=c4[2]-'A';
				if(a+1==b||a-1==b) cout << 1;
				else cout << 0;
			}  
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
/*
100
Trick||Treat!!!
while(1) RP++; 
*/
