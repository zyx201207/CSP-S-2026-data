#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rcx,xcx,rzw,xzw;
	cin>>rcx>>rzw>>xcx>>xzw;
	if((rcx[0]!=xcx[0])||(rcx[1]!=xcx[1])){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else if(!(rzw[0]==xzw[0]&&rzw[1]==xzw[1])){
		cout<<1<<0<<0<<0;
		return 0;
	}
	else if(!((rzw[2]<='C'&&xzw[2]<='C')||(rzw[2]>'C'&&xzw[2]>'C'))){
		cout<<1<<1<<0<<0;
		return 0;
	}
	else if(!(rzw[2]>'C'||rzw[2]-xzw[2]==1||xzw[2]-rzw[2]==1)){
		cout<<1<<1<<1<<0;
		return 0;
	}
	cout<<1<<1<<1<<1;
	return 0;
} 
//  
