#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int rc,xc;
	char rz[3],xz[3];
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<1;
		int rz1=(rz[0]-'0')*10+rz[1];
		int xz1=(xz[0]-'0')*10+xz[1];
		char op1=rz[2],op2=xz[2];
		if(op2=='F') op2='E';
		if(rz1==xz1){
			cout<<1;
			if(op1==op2+1&&op2!='C') cout<<11;
			else if(op1==op2-1&&op1!='C') cout<<11;
			else if((op1=='A'||op1=='B'||op1=='C')&&(op2=='A'||op2=='B'||op2=='C')) cout<<10;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
