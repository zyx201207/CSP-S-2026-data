//GZ-J00058,ÈÎ²ªÓî£¬Ê®¾ÅÖÐ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if((a[1]==c[1])&&(a[2]==c[2])){
		if(b[0]==d[0]&&b[1]==d[1]){
			if((b[3]<'d'&&d[3]<'d')||(b[3]>'c'&&d[3]>'c')){
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='A'&&b[2]=='B')||(d[2]=='B'&&b[2]=='C')||(d[2]=='D'&&b[2]=='F')){
					cout << 1111;
				}else{
					cout << 1110;
				}
			}else{
				cout << 1100;
			}
		}else{
			cout << 1000;
		}
	}else{
		cout << "0000";
	}
	return 0;
}
