//GZ-J00050   遵义市第53中学    龙炫宇； 

#include<bits/stdc++.h>
using namespace std;


int main(){

	
	string c,cn,s,sn;
	cin>>c>>cn>>s>>sn;
	if(c==s){
		
		if(cn[0]==sn[0]&&cn[1]==sn[1]){

			if(cn[2]<='C'&&sn[2]<='C'&&cn[2]>='A'&&sn[2]>='A'){
				if(cn[2]=='A'&&sn[2]=='B'||cn[2]=='C'&&sn[2]=='B'||cn[2]=='B'&&sn[2]=='A'||cn[2]=='B'&&sn[2]=='C'){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else if(cn[2]=='D'&&sn[2]=='F'||cn[2]=='F'&&sn[2]=='D'){
					if(cn[2]=='D'&&sn[2]=='F'||cn[2]=='F'&&sn[2]=='D'){
						cout<<1111;
					}
					else{
				cout<<1110;
					}
			}
			else if(cn[2]<='C'&&cn[2]>='A'&&sn[2]=='D'||cn[2]<='C'&&cn[2]>='A'&&sn[2]=='F'||sn[2]<='C'&&sn[2]>='A'&&sn[2]=='D'||sn[2]<='C'&&sn[2]>='A'&&sn[2]=='F'){
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	
	}
	else{
		cout<<0000;
	}
	
	return 0;
}
