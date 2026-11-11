#include<bits/stdc++.h>
using namespace std;
int rrr=0,xxx=0;
string rr,xx;
int main(){

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

cin>>rrr>>rr>>xxx>>rr;
if(rrr==xxx){
	cout<<"1";
	if(rr[0]==xx[0]){
		cout<<"1";
	}else{
		cout<<"0";
		}
	if(rr[1]==xx[1]){
		cout<<"1";
	}else{
		cout<<"0";
		}
	if(rr[2]=='D' and xx[2]=='C'){
		}else if(rr[2]=='C' and xx[2]=='D'){
			if(rr[2]==xx[2]-1){
		cout<<"1";
		}if(rr[2]-1==xx[2]){
		cout<<"0";
		}
			}
	}else{
		cout<<"0000";
		}
	
	
}
