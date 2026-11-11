#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r5,x1,x5;
	cin>>r1>>r5>>x1>>x5;
	string r2,x2;
	char r3,x3;
	r2+=r5[0]+r5[1];
	x2+=x5[0]+x5[1];
	r3=r5[2];
	x3=x5[2];
	if(r1==x1){
		cout<<"1";
		if(r2==x2){
			cout<<"1";
			if(r3<='C'&&x3<='C'){
				cout<<"1";
				if((r3=='A'&&x3=='B')||(r3=='B'&&x3=='A')||(r3=='B'&&x3=='C')||(r3=='C'&&x3=='B')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(r3>='D'&&x3>='D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
}
