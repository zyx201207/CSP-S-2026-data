#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rb,xb;
	int ra,xa;
	cin>>ra>>rb>>xa>>xb;
	if(ra==xa){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(rb[0]==xb[0] && rb[1]==xb[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((rb[2]-'A'<=2 && xb[2]-'A'<=2)||(rb[2]-'A'>2 && xb[2]-'A'>2)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(rb[2]-xb[2])==1 || (rb[2]=='D' && xb[2]=='F')  || (xb[2]=='D' && rb[2]=='F')){
		cout<<1;
		return 0;
	}
	else {
		cout<<0;
	}
	return 0;
} 
