#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int fl=0; 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//同节车厢 
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<"1";
		fl=1;
	}
	else cout<<"0";
	//同排座位 
	if(fl==1){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			fl=1;
		}
		else{
			cout<<"0";
			fl=0;
		}
	}
	else cout<<"0";
	//同侧座位
	if(fl==1){
		if(s1[2]=='A'&& (s2[2]=='B' || s2[2]=='C'))fl=1;
		else if(s1[2]=='B'&& (s2[2]=='A' || s2[2]=='C'))fl=1;
		else if(s1[2]=='C'&& (s2[2]=='B' || s2[2]=='A'))fl=1;
		else if(s1[2]=='D'&& s2[2]=='F')fl=1;
		else if(s1[2]=='F'&& s1[2]=='D')fl=1;
		else fl=0;
	}
	if(fl==1)cout<<"1";
	else cout<<"0";
	//相邻座位
	if(fl==1){
		if((s1[2]=='A'&&s2[2]=='B') || (s1[2]=='B'&&s2[2]=='A'))fl=1;
		else if((s1[2]=='B'&&s2[2]=='C') || (s1[2]=='C'&&s2[2]=='B'))fl=1;
		else if((s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F'&&s2[2]=='D'))fl=1;
		else fl=0;
	}
	if(fl==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
