#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	
	if(ra==xa){cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(rb[0]==xb[0]&&rb[1]==xb[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}

	if((rb[2]=='C'&&xb[2]=='D')||(rb[2]=='D'&&xb[2]=='C')){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	} 
	
	if((rb[2]=='C'&&xb[2]=='A')||(rb[2]=='A'&&xb[2]=='C')){
		cout<<"0";
		return 0;
	}
	else{
		cout<<"1";
	} 
	
	return 0;
}
