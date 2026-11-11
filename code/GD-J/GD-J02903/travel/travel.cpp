#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xa,xb,za,zb;
	char ch;
	long long ta,tb;
	cin>>xa>>za>>xb>>zb;
	if(xa!=xb){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(za[0]==zb[0] && za[1]==zb[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(za[2]=='A') ta=1;
	if(za[2]=='B') ta=2;
	if(za[2]=='C') ta=3;
	if(za[2]=='D') ta=5;
	if(za[2]=='F') ta=6;
	//
	if(zb[2]=='A') tb=1;
	if(zb[2]=='B') tb=2;
	if(zb[2]=='C') tb=3;
	if(zb[2]=='D') tb=5;
	if(zb[2]=='F') tb=6;
	//
	if(ta>4 && tb>4) cout<<"1";
	else if(ta<4 && tb<4) cout<<"1";
	else{
		cout<<"00";
		return 0; 
    }
    //
    if(ta-tb==1 || ta-tb==-1){
    	cout<<"1";
	}
	else cout<<"0";
}
