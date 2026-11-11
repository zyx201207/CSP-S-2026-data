#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr[0] != cx[0]||cr[1]!=cx[1]) {
		cout<<"0000";
		return 0;
	}
	if(sr[0]!=sx[0]||sr[1]!=sx[1]) {
		cout<<"1000";	
		return 0;
	}
	if(sr[2]>='A'&&sr[2]<='C'){
		if(sx[2]<'A'||sx[2]>'C'){
			cout<<"1100";
			return 0;
		}
	}	
	if(sr[2]=='D'||sr[2]=='F'){
		if(sx[2]!='D'||sx[2]!='F'){
			cout<<"1100";
		}
	}
	
	if(sr[2]=='D'){
		if(sx[2]!='F') cout<<"1110";
		return 0;
	}
	if(sr[2]=='F'){
		if(sx[2]!='D') cout<<"1110";
		return 0;
	}
	if(sx[2]=='D'){
		if(sr[2]!='F') cout<<"1110";
		return 0;
	}
	if(sx[2]=='F'){
		if(sr[2]!='D') cout<<"1110";
		return 0;
	}
	if(sr[2]=='A'&&sx[2]=='C'){
		cout<<"1110";
		return 0;
	}
	if(sx[2]=='A'&&sr[2]=='C'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
