#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	string rx,xx;
	cin>>r>>rx>>x>>xx;
	if(r==x){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(rx[0]==xx[0]&&rx[1]==rx[1]){
	   cout<<"1";	
	}else{
		cout<<"000";
		return 0;
	}
	if(((rx[2]=='A'||rx[2]=='B'||rx[2]=='C')&&(xx[2]=='A'||xx[2]=='B'||xx[2]=='C'))||((rx[2]=='D'||rx[2]=='F')&&(xx[2]=='D'||xx[2]=='F'))){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((rx[2]=='A'&&xx[2]=='B')||(rx[2]=='B'&&xx[2]=='A')||(rx[2]=='B'&&xx[2]=='C')||(rx[2]=='C'&&xx[2]=='B')||(rx[2]=='D'&xx[2]=='F')||(rx[2]=='F'&&xx[2])=='D'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
