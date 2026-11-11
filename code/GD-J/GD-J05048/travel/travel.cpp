#include<bits/stdc++.h>
using namespace std;

string tr,tx,sr,sx;
bool st1=1,st2=1,st3=1,st4=1; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>tr>>sr>>tx>>sx;
	if(tr!=tx){
		cout<<"0000";
		return 0; 
	}
	int seatr=10*(sr[0]-'0')+(sr[1]-'0'),seatx=10*(sx[0]-'0')+(sx[1]-'0');
	if(seatr!=seatx){
		cout<<"1000";
		return 0;
	}
	char lseatr=sr[2],lseatx=sx[2];
	if(('A'<=lseatr||lseatr<='C')&&(lseatx=='D'||lseatx=='F')){
		cout<<"1100";
		return 0;
	}
	if(max(lseatr,lseatx)-min(lseatr,lseatx)==1) cout<<"1111";
	else cout<<"1110";
	
	return 0;
} 
