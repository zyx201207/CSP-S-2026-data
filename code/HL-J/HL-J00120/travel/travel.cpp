#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rb,Xb,Ra,Xa;
	cin>>Ra>>Rb>>Xa>>Xb;
	if(Ra==Xa){
		cout<<1;
		char l=Rb[2],r=Xb[2];
		if(Rb[0]==Xb[0] and Rb[1]==Xb[1]){
			cout<<1;
			if(l-'A'>2 and r-'A'>2 or l-'A'<3 and r-'A'<3){
				cout<<1;
				if((l-'A')-(r-'A')==1 or (r-'A')-(l-'A')==1){
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
	else{
		cout<<"0000";
	}
return 0;
}
