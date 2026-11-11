#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string chexiang1,chexiang2,zwh1,zwh2;
	bool cx=0,p=0,ce=0,ai=0;
	cin>>chexiang1>>zwh1>>chexiang2>>zwh2;
	if(chexiang1==chexiang2) cx=1;
	if(zwh1[0]==zwh2[0]&&zwh1[1]==zwh2[1]) p=1;
	if(zwh1[2]>='A'&&zwh2[2]>='A'&&zwh1[2]<='C'&&zwh2[2]<='C') ce=1;
	if(zwh1[2]>='D'&&zwh2[2]>='D'&&zwh1[2]<='F'&&zwh2[2]<='F') ce=1;
	if(zwh1[2]=='A'&&zwh2[2]=='B') ai=1;if(zwh1[2]=='B'&&zwh2[2]=='A') ai=1;
	if(zwh1[2]=='B'&&zwh2[2]=='C') ai=1;if(zwh1[2]=='C'&&zwh2[2]=='B') ai=1;
	if(zwh1[2]=='D'&&zwh2[2]=='F') ai=1;if(zwh1[2]=='F'&&zwh2[2]=='D') ai=1;
	if(cx==0){
		p=0;
		ce=0;
		ai=0;
	} 
	if(p==0){ ce=0; ai=0;
	}
	cout<<cx<<p<<ce<<ai;
	return 0;
}
