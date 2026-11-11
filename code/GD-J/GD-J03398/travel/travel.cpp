#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string sR,sX;
int cR,cX,sRn,sXn;
bool Rleft,Xleft;
char ans[4]={'0','0','0','0'},sRs,sXs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cR>>sR>>cX>>sX;
	sRn=stoi(sR.substr(0,2));
	sXn=stoi(sX.substr(0,2));
	sRs=sR[2];
	sXs=sX[2];
	if(sRs=='A'||sRs=='B'||sRs=='C'){
		Rleft=1;
	}
	if(sXs=='A'||sXs=='B'||sXs=='C'){
		Xleft=1;
	}
	
	if(cR==cX){
		cout<<1;
		if(sRn==sXn){
			cout<<1;
			if(Rleft==Xleft){
				cout<<1;
				char a=min(sRs,sXs),b=max(sRs,sXs);
				if(b=='F'){
					b--;
				}
				if(a+1==b){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

