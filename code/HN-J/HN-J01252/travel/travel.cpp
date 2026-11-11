#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,sx,cr,sr;
	cin>>cx>>sx>>cr>>sr;
	int n=0,u=0;
	for(int i=0;i<2;i++){
		if(cx[i]!=cr[i]) n+=1;
		if(sx[i]!=sr[i]) u+=1;
	}
	if(n>=1){
		cout<<"0000";
		return 0;
	}
	if(u>=1){
		cout<<"1000";
		return 0;
	}else cout<<"11";
	if (sx[2]=='A'){
		if(sr[2]=='B') cout<<"11";	
		else if(sr[2]=='C') cout<<"10";
		else if(sr[2]=='D'||sr[2]=='F') cout<<"00";
	}else if(sx[2]=='B'){
		if(sr[2]=='A'||sr[2]=='C') cout<<"11";	
		else if(sr[2]=='D'||sr[2]=='F') cout<<"00";
	}else if(sx[2]=='C'){
		if(sr[2]=='B') cout<<"11";	
		else if(sr[2]=='A') cout<<"10";
		else if(sr[2]=='D'||sr[2]=='F') cout<<"00";
	}else if(sx[2]=='D'){
		if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C') cout<<"00";
		else if(sr[2]=='F') cout<<"11";
	}else if(sx[2]=='D'){
		if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C') cout<<"00";
		else if(sr[2]=='D') cout<<"11";
	}
	return 0;
}
