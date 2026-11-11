#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	bool p=0;
	if(r2[0]==x2[0]&&r2[1]==x2[1]){
		if(r2[2]=='D'||r2[2]=='F'){
			if(x2[2]=='D'||x2[2]=='f'){
				cout<<"1";
				p=1;
			}
		}
		if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
			if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
				cout<<"1";
				p=1;
			}
		}
	}
	if(p==0){
		cout<<"0";
	}
	p=0;
	if(r2[0]==x2[0]&&r2[1]==x2[1]){
		if(r2[2]=='D'||r2[2]=='F'){
			if(x2[2]=='D'||x2[2]=='f'){
				cout<<"1";
				p=1;
			}
			else{
				cout<<"0";
				p=1;
			}
		}
		if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
			if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
				if(r2[2]=='A'&&x2[2]=='C'){
					cout<<"0";
					p=1;
				}
				else if(x2[2]=='A'&&r2[2]=='C'){
					cout<<"0";
					p=1;
				}
				else{
					cout<<"1";
					p=1;
				}
			}
		}
	}
	if(p==0){
		cout<<"0";
	}
	return 0;
}
