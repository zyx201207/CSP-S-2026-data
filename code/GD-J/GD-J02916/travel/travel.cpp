#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ss1,ss2;
char sss1,sss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000",exit(0); 
	}
	else if(s1==s3){
		cout<<"1";
		ss1=s2[0]+s2[1];
		ss2=s4[0]+s4[1];
		if(ss1==ss2){
			cout<<"1";
			sss1=s2[2];
			sss2=s4[2];
			if(sss1=='A'){
				if(sss2=='B'||sss2=='C'){
					cout<<"1";
					if(sss2=='B') cout<<"1",exit(0);
					else cout<<"0",exit(0);
				}
				else cout<<"00",exit(0);
			}
			if(sss1=='B'){
				if(sss2=='A'||sss2=='C') {
					cout<<"11",exit(0);
				}
				else cout<<"00",exit(0);
			}
			if(sss1=='C'){
				if(sss2=='A'||sss2=='B') {
					cout<<"1";
					if(sss2=='B') cout<<"1",exit(0);
					else cout<<"0",exit(0);
				}
				else cout<<"00",exit(0);
			}
			if(sss1=='D'){
				if(sss2=='F') {
					cout<<"11",exit(0);
				}
				else cout<<"00",exit(0);
			}
			if(sss1=='F'){
				if(sss2=='D') {
					cout<<"11",exit(0);
				}
				else cout<<"00",exit(0);
			}
		} 
		else cout<<"000";	
	} 
} 
