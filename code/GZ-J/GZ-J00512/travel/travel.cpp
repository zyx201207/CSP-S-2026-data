//GZ-J00512 易煊培 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

string Rroom,Rseat,Xroom,Xseat;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Rroom>>Rseat>>Xroom>>Xseat;
	if((Rroom[0]==Xroom[0])&&(Rroom[1]==Xroom[1])){
		cout<<'1';
		if(Rseat[0]==Xseat[0]&&Rseat[1]==Xseat[1]) {
			cout<<'1';
			if(Rseat[2]<='C'&&Xseat[2]<='C'&&Rseat[2]>='A'&&Xseat[2]>='A') {
				cout<<'1';
				if(abs(Rseat[2]-Xseat[2])==1) cout<<'1';
				else cout<<'0';
			}
			else if(Rseat[2]<='F'&&Xseat[2]<='F'&&Rseat[2]>='D'&&Xseat[2]>='D'){
				cout<<'1';
				if(abs(Rseat[2]-Xseat[2])==1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}  
