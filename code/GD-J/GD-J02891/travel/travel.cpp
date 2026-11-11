#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,sr1,sc1,c2,sr2,sc2,s1,s2;
	cin>>c1>>s1>>c2>>s2; 
	
	sr1=s1[2];
	sr2=s2[2];
	sc1=s1[0];
	sc1=s1[1];
	sc2=s2[0];
	sc2=s2[1];
	if(sr1=="A"){
		sr1="1";
	}
	else if(sr1=="B"){
		sr1="2";
	}
	else if(sr1=="C"){
		sr1="3";
	}
	else if(sr1=="D"){
		sr1="5";
	}
	else if(sr1=="F"){
		sr1="6";
	}
	//-----------------------------------
	if(sr2=="A"){
		sr2="1";
	}
	else if(sr2=="B"){
		sr2="2";
	}
	else if(sr2=="C"){
		sr2="3";
	}
	else if(sr2=="D"){
		sr2="5";
	}
	else if(sr2=="F"){
		sr2="6";
	}
	
	int sri1,sci1,sri2,sci2;
	sri1 = stoi(sr1);
	sci1 = stoi(sc1);
	sri2 = stoi(sr2);
	sci2 = stoi(sc2);

	int ans=0,tc=0;
	if(c1==c2){
		ans+=1000;
		if(sci1==sci2){
			ans+=100;
			if(((sri1==1||sri1==2||sri1==3)&&(sri2==1||sri2==2||sri2==3))||((sri1==5||sri1==6)&&(sri2==5||sri2==6))){
				ans+=10;
				tc=1;
			}
		}
		if(tc==1){
			if((sri1==sri2&&(sci1==sci2+1||sci1==sci2-1))||(sci1==sci2&&(sri1==sri2+1||sri1==sri2-1))){
				ans+=1;
			}
		}
		cout<<ans;
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
