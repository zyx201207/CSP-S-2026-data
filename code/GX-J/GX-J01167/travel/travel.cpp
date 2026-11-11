#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cxa,cxb;
	int ans=0;
	string zwa,zwb;
	cin>>cxa>>zwa>>cxb>>zwb;
	if(cxa==cxb) ans++;
	else {
		cout<<"0000";
		return 0;
	}
	
	if(zwa[0]==zwb[0]&&zwa[1]==zwb[1]){
		ans*=10;ans+=1;
	}
	else {
		cout<<"1000";
		return 0;
	}
	
	if(((zwa[2]>=65&&zwa[2]<=67)&&(zwb[2]>=65&&zwb[2]<=67))||((zwa[2]>=68&&zwa[2]<=70)&&(zwb[2]>=68&&zwb[2]<=70))){
		ans*=10;ans+=1;
	}
	else {
		cout<<"1100";
		return 0;
	}
	
	if((zwa[2]>=65&&zwa[2]<=67)&&(zwb[2]>=65&&zwb[2]<=67)){
		if(zwa[2]-zwb[2]==1||zwb[2]-zwa[2]==1){
			ans*=10;ans+=1;
		}
	}
	
	if((zwa[2]>=68&&zwa[2]<=70)&&(zwb[2]>=68&&zwb[2]<=70)){
		if(zwa[2]-zwb[2]==2||zwb[2]-zwa[2]==2){
			ans*=10;ans+=1;
		}
	}
	else {
		cout<<"1110";
		return 0;
	}
	
	
	char anss=(char)ans;
	cout<<anss;
	
	return 0;
}
