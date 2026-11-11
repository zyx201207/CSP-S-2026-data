#include<bits/stdc++.h>
using namespace std;
bool samel(string a,string b){
	if(((a=="D"&&b=="F")||(a=="F"&&b=="D"))||((a=="A"||a=="B"||a=="C")&&(b=="A")||(b=="B")||(b=="C")))return 1;
	return 0;
}
bool samer(string a, string b){
	if((a=="D")||(b=="D")||(a=="B")||(b=="B"))return 1;
	return 0;    
}
string rxiang,xxiang,rseat,xseat,rp,xp,rh,xh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rxiang>>rseat>>xxiang>>xseat;
    if(rxiang!=xxiang){
    	cout<<"0000";
    	return 0;
    }
    rp=rseat[0]+rseat[1];
    xp=xseat[0]+xseat[1];
    if(rp!=xp){
    	cout<<"1000";
    	return 0;
    }
    rh=rseat[2],xh=xseat[2];
    if(!samel(rh,xh)){
    	cout<<"1100";
    	return 0;
    }
    if(!samer(rh,xh)){
    	cout<<"1110";
    	return 0;
    }
    cout<<"1111";
	return 0;
}

