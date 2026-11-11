#include<bits/stdc++.h>
using namespace std;
long long rx,xx,rp,xp;
char rz[5],xz[5];

long long zh(char a){
	switch(a){
		case 'A':
			return 1;
		case 'B':
			return 2;
		case 'C':
			return 3;
		case 'D':
			return 4;
		case 'F':
			return 5;
}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>rz>>xx>>xz;
	rp=(rz[0]-'0')*10+rz[1]-'0';
	xp=(xz[0]-'0')*10+xz[1]-'0';
	
	if(rx==xx){
		cout<<1;
	if(rp==xp){
		cout<<1;
	if((zh(rz[2])<=3&&zh(xz[2])<=3)||(zh(rz[2])>=4&&zh(xz[2])>=4)){
		cout<<1;
	if(abs(zh(rz[2])-zh(xz[2]))==1){
		cout<<1;
	}else cout<<0;
	}else cout<<"00";
	}else cout<<"000";	
	}else cout<<"0000";

	/*cout<<rx<<rp<<rz[2]<<endl;
	cout<<xx<<xp<<xz[2]<<endl;*/
	
	return 0;
}
