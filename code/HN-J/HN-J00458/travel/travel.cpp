#include <bits/stdc++.h>
using namespace std;
string ca,cb;
string line1,line2;
bool bj=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>line1>>cb>>line2;
	if(ca!=cb){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(line1.substr(0,2)!=line2.substr(0,2)){
			cout<<"000";
		}
		else{
			cout<<1;
			if(!((line2[2]<='C'&&line1[2]<='C')||(line2[2]>'C'&&line1[2]>'C'))){
				cout<<"00";
			}
			else{
				cout<<1;
				if(abs(line1[2]-line2[2])!=1){
					cout<<"0";
				}
				else cout<<1;
			}
		}
	}
	return 0;
}
