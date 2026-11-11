#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string xx,yy;
	cin>>x>>xx>>y>>yy;
	if(x==y) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	char a[3]={},b[3]={};
	a[0] = xx[0];
	b[0] = yy[0];
	a[1] = xx[1];
	b[1] = yy[1];
	a[2] = xx[2];
	b[2] = yy[2];
	if((a[0] == b[0]) && (a[1] == b[1])) cout<<"1";
	else{
		cout<<"000";
		return 0;	
	} 
	if(a[2] == 'A'){
		if(b[2]=='B' || b[2]=='C') cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	if(a[2] == 'B'){
		if(b[2]=='A' || b[2]=='C') cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	if(a[2] == 'C'){
		if(b[2]=='B' || b[2]=='A') cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	if(a[2] == 'D'){
		if(b[2]=='F') cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	if(a[2] == 'F'){
		if(b[2]=='D') cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	
	
	if(a[2] == 'A'){
		if(b[2]=='B') cout<<"1";
		else {
			cout<<"0";
			return 0;
		}
	}
	if(a[2] == 'B'){
		if(b[2]=='A' || b[2]=='C') cout<<"1";
		else {
			cout<<"0";
			return 0;
		}
	}
	if(a[2] == 'C'){
		if(b[2]=='B') cout<<"1";
		else {
			cout<<"0";
			return 0;
		}
	}
	if(a[2] == 'D'){
		if(b[2]=='F') cout<<"1";
		else {
			cout<<"0";
			return 0;
		}
	}
	if(a[2] == 'F'){
		if(b[2]=='D') cout<<"1";
		else {
			cout<<"0";
			return 0;
		}
	}
}

