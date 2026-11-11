#include<bits/stdc++.h>
using namespace std;
string Ra,Rb,Xa,Xb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Ra>>Rb>>Xa>>Xb;
	if(Ra!=Xa){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(Rb[0]==Xb[0]&&Rb[1]==Xb[1]){
			cout<<1;
			if((Rb[2]<'D'&&Xb[2]<'D')||(Rb[2]>'C'&&Xb[2]>'C')){
				cout<<1;
				if(Rb[2]=='B'||Xb[2]=='B'){
					cout<<1;
				}
				else if(Rb[2]>'C'&&Xb[2]>'C'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}
