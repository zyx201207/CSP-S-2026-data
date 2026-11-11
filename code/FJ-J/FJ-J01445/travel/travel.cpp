#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2;
int f=1,f1=1,f2=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f=2;
		}
	}
	if(f==2){
		cout<<"000";
		return 0;
	}
	else{
		 cout<<1;
	}
	if(s1[2]=='D' || s1[2]=='F'){
		 f1=2;
	}
		if(s2[2]=='D' || s2[2]=='F'){
		 f2=2;
	}
	if(f1==f2){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0; 
	}
	int g1=s1[2]-'0';
	
	int g2=s2[2]-'0';
	if(abs(g1-g2)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
