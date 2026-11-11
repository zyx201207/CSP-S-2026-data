#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<1;
	else{
		cout<<"0000"; 
		return 0;
	}
	string c5,c6;
	for(int i=0;i<2;i++){
		c5+=c2[i];
		c6+=c4[i];
	}
	if(c5==c6) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if(c2[2]<='C'&&c4[2]<='C'){
		cout<<1;
		if(c2[2]=='B'||c4[2]=='B') cout<<1;
		else cout<<0;
	}
	else if(c2[2]>='D'&&c4[2]>='D'){
		cout<<"11"; 
	}
	else cout<<"00";
	return 0; 
} 
