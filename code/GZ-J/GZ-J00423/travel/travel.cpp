//GZ-J00423 兴义市弘毅中学 王富俊
#include<bits/stdc++.h>
using namespace std;

char ac[2],az[3],bc[2],bz[3];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>ac[0]>>ac[1]>>az[0]>>az[1]>>az[2]>>bc[0]>>bc[1]>>bz[0]>>bz[1]>>bz[2];

	if(ac[0]==bc[0]&&ac[1]==bc[1]){
		cout<<"1";
		if(az[0]==bz[0]&&az[1]==bz[1]){
			cout<<"1";
			if(((az[2]<='C'&&az[2]>='A')&&(bz[2]<='C'&&bz[2]>='A'))||((az[2]<='F'&&az[2]>='D')&&(bz[2]<='F'&&bz[2]>='D'))){
				cout<<"1";
				if(((az[2]=='C'&&bz[2]=='B')||(az[2]=='B'&&bz[2]=='A'))||((az[2]=='B'&&bz[2]=='C')||(az[2]=='A'&&bz[2]=='B'))){
					cout<<"1";
				}
				else if((az[2]<='F'&&az[2]>='D')&&(bz[2]<='F'&&bz[2]>='D')){
					cout<<"1";
				}
				else cout<<"0";
			}
			
			else cout<<"00";
		}
		
		else{cout<<"000";}
	}
	
	else{cout<<"0000";}
	return 0;
} 
 
