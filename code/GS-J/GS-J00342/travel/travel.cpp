#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
string a2,a4;
char s2,s4;
int i=0,a=0;
int main(){

	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	a2=c2[0]+c2[1];
	a4=c4[0]+c4[1];
	s2=c2[2];
	s4=c4[2];
	if(c1=="01") i+=1;
	if(c1=="16") i+=1;
	if(c3=="01") i+=1;
	if(c3=="16") i+=1;
	if((s2=='A'&&s4=='B')||(s4=='A'&&s2=='B'))a+=1;
	if((s2=='B'&&s4=='C')||(s4=='B'&&s2=='C'))a+=1;
	if((s2=='D'&&s4=='F')||(s4=='D'&&s2=='F'))a+=1;


	if(i==0){
		if(c1==c3){
			cout<<"1";
			if(a2==a4){
				cout<<"1";
				if(s2<='C'&&s4<='C')i+=1;
				if(s2>='D'&&s4>='D')i+=1;
				if(i==1){
					cout<<"1";
					if(a==1){
						cout<<"1";
					}
					else cout<<"0";
				}
				else cout<<"00";
			}
			else cout<<"000";
		}
		else cout<<"0000";
	}	
	else cout<<"0000";
	return 0;
}
