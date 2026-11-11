#include<bits/stdc++.h>
using namespace std;
struct HU{
	string c,p;
};
HU a[5];
string s[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f=0;
	int h=0;
	int g=0;
	int q=0;
    for(int i=1;i<=2;i++){
    	cin>>a[i].c>>a[i].p;
	}
	if(a[1].c==a[2].c){
		g=1; 
	}
	else{
		g=0;
	}
	string n=a[1].p;
	string m=a[2].p;
	for(int i=0;i<=1;i++){
		s[1]+=n[i];
		s[2]+=m[i];
	}
	s[3]=n[2];
	s[4]=m[2];
	if(s[1]==s[2]){
		q=1;
	}
	else{
		q=0;
	}
    if(s[3]=="A" && s[4]=="B"){
		f=1;
	}
	else if(s[3]=="A" && s[4]=="c"){
		f=1;
	}
    else if(s[3]=="B" && s[4]=="A"){
		f=1;
	}
	else if(s[3]=="B" && s[4]=="c"){
		f=1;
	}
	else if(s[3]=="C" && s[4]=="A"){
		f=1;
	}
	else if(s[3]=="C" && s[4]=="B"){
		f=1;
	}
	else if(s[3]=="D" && s[4]=="F"){
		f=1;
	}
	if(s[3]=="A" && s[4]=="B"){
		h=1;
	}
	else if(s[3]=="B" && s[4]=="A"){
		h=1;
	}
	else if(s[3]=="B" && s[4]=="C"){
		h=1;
	}
	else if(s[3]=="C" && s[4]=="B"){
		h=1;
	}
	else if(s[3]=="D" && s[4]=="F"){
		h=1;
	}
	else if(s[3]=="F" && s[4]=="D"){
		h=1;
	}
	else{
		h=0;
	}
	if(g!=0){
	  if(q!=0){
	  	if(f!=0){
	  		if(h!=0){
	  			cout<<"1111";
			  }
			  else{
			  	cout<<"1110";
			  }
		  }
		  else{
		   cout<<"1100";	
		  }
	  }
	  else{
	  	cout<<"1000";
	  }	
	}
	else{
		cout<<"0000";
	}
	return 0;
}


