// GZ-J00094 清镇市第一中学 蒋煜
#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> ca >> sa >> cb >> sb;
	if(ca==cb){
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			if(sa[2]<='C'&&sb[2]<='C'){
				if(sa[2]-sb[2]==1||sb[2]-sa[2]==1){
					cout << 1111;
				}else{
					cout<< 1110;
				}
			}
			else if(sa[2]>'C'&&sa[2]<='F'&&sa[2]!='E'&&sb[2]>='C'&&sb[2]<='F'&&sb[2]!='E'){
				if(sa[2]-sb[2]==2||sb[2]-sa[2]==2){
					cout << 1111;
				}else{
					cout<< 1110;
				}
			}
			else{
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
