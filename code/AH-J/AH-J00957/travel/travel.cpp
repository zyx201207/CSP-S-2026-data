#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else {
		cout<<"0000";
		return 0;
	}
	string numc;
	string numb;
	string zmc;
	string zmb;
	numc="";numb="";zmc="";zmb=""; 
	for(int i=0; i<s1.size(); i++){
		if(s1[i]<='9'&&s1[i]>='0')numc+=s1[i];
		if(s1[i]<='Z'&&s1[i]>='A')zmc+=s1[i];
	} 
	for(int i=0; i<s2.size(); i++){
		if(s2[i]<='9'&&s2[i]>='0')numb+=s2[i];
		if(s2[i]<='Z'&&s2[i]>='A')zmb+=s2[i];
	} 
	if(numc==numb)cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if((zmc=="A"&&(zmb=="B"||zmb=="C"))||(zmc=="B"&&(zmb=="A"||zmb=="C"))||(zmc=="C"&&(zmb=="B"||zmb=="A"))||(zmc=="D"&&zmb=="F")||(zmc=="F"&&zmb=="D")){
		cout<<'1';
	}else cout<<'0';
	if(zmc=="A"&&zmb=="B"||zmc=="B"&&zmb=="C"||zmc=="D"&&zmb=="F"||zmc=="F"&&zmb=="D"||zmb=="A"&&zmc=="B"||zmb=="B"&&zmc=="C"||zmb=="D"&&zmc=="F"&&zmb=="F"&&zmc=="D"){
		cout<<'1';
	}else cout<<'0';
	return 0;
} 
