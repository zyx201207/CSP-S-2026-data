#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,az,bx,bz;
	cin>>ax>>az>>bx>>bz;
	if(ax==bx){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int pa=int((az[0]-'0')+(az[1]-'0'));
	int pb=int((bz[0]-'0')+(bz[1]-'0'));
	if(pa==pb){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char ca=az[2];
	char cb=bz[2];
	if(ca=='A'||ca=='B'||ca=='C'){
		if(cb=='A'||cb=='B'||cb=='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(cb=='D'||cb=='F'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(ca+1==cb||ca-1==cb){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
