#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string k1,k2,u1,u2;
	long long l=0;
	cin>>k1>>u1>>k2>>u2;
	if(k1==k2) {
		cout<<1;
		l++;	
	}else cout<<0;	
	if(u1[0]==u2[0] && u1[1]==u2[1] && l==1){
		cout<<1;
		l++;
	}else cout<<0;	
	if(((u1[2]=='A'&&u2[2]=='B') || (u1[2]=='B'&&u2[2]=='A') || (u1[2]=='C'&&u2[2]=='B') || (u1[2]=='B'&&u2[2]=='C') || (u1[2]=='A'&&u2[2]=='C') || (u1[2]=='C'&&u2[2]=='A') || (u1[2]=='D'&&u2[2]=='F') || (u1[2]=='F'&&u2[2]=='D'))&& l==2) {
		cout<<1;
		l++;
		}else cout<<0;
		if(((u1[2]=='A'&&u2[2]=='B') || (u1[2]=='B'&&u2[2]=='A') || (u1[2]=='C'&&u2[2]=='B') || (u1[2]=='B'&&u2[2]=='C') || (u1[2]=='D'&&u2[2]=='F')|| (u1[2]=='F'&&u2[2]=='D')) && l==3){
		cout<<1;
		}else cout<<0;																																										
	return 0;
	}
