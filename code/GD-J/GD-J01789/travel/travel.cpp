#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string x1,x2;
	string z1,z2;
	cin>>x1>>z1>>x2>>z2;
	if(x1==x2){
		cout<<"1";
		if(z1[0]==z2[0]&&z1[1]==z2[1]){
			cout<<"1";
			if((z1[2]<='C'&&z2[2]<='C')||(z1[2]>='D'&&z2[2]>='D')){
				cout<<"1";
				if(z1[2]>z2[2]){
					if(z1[2]!='D'&&z1[2]-z2[2]==1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					if(z2[2]!='D'&&z1[2]-z2[2]==-1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
