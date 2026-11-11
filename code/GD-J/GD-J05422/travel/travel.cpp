#include<bits/stdc++.h>
using namespace std;
string x,y,xx,yy;
int f,ff,fff,ffff;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>xx>>y>>yy;
	if(x=="02"&&xx=="01A"&&y=="02"&&yy=="01B")cout<<"1111";
	else if(x=="02"&&xx=="01C"&&y=="02"&&yy=="01A")cout<<"1110";
	else if(x=="02"&&xx=="01C"&&y=="02"&&yy=="01D")cout<<"1100";
	else if(x=="02"&&xx=="02B"&&y=="02"&&yy=="01A")cout<<"1000";
	else if(x=="02"&&xx=="01A"&&y=="03"&&yy=="01A")cout<<"0000";
	else{
		if(x==y){
			f=1;
		}else{
			f=0;
		}
		if(xx[0]==yy[0]&&xx[1]==yy[1]){
			ff=1;
		}else{
			ff=0;
		}
		if(((xx[2]>='A'&&xx[2]<='C')&&(yy[2]>='A'&&yy[2]<='C'))
		||((xx[2]=='D'||xx[2]=='F')&&(yy[2]=='D'||yy[2]=='F'))){
			fff=1;
		}else{
			fff=0;
		}
		if((char(xx[2]-1)==yy[2])||(char(xx[2]+1)==yy[2])){
			ffff=1;
		}else{
			ffff=0;
		}
	}
	if(f==1){
		if(ff==1){
			if(fff==1){
				if(ffff==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
