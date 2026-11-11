#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool k1=0,k2=0,k3=0,k4=0; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			k1=1;
		}
	}
	if(k1==1){
		cout<<0;
	}else{
		cout<<1;
	}
	
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			k2=1;
		}
	}
	
	if(k2!=1&&k1!=1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if(s1[2]=='F'&&s2[2]=='D'&&k2==0){
		k3=1;
		k4=1;
	}
	else if(s2[2]=='F'&&s1[2]=='D'&&k2==0){
		k3=1;
		k4=1;
	}
	
	else if(s1[2]=='A'&&s2[2]=='B'&&k2==0){
		k3=1;
		k4=1;
	}
	else if(s1[2]=='A'&&s2[2]=='C'&&k2==0){
		k3=1;
	}
	else if(s2[2]=='A'&&s1[2]=='B'&&k2==0){
		k3=1;
		k4=1;
	}
	else if(s2[2]=='A'&&s1[2]=='C'&&k2==0){
		k3=1;
	}
	
	else if(s1[2]=='B'&&s2[2]=='C'&&k2==0){
		k3=1;
		k4=1;
	}
	else if(s2[2]=='B'&&s1[2]=='C'&&k2==0){
		k3=1;
		k4=1;
	}
	
	if(k3==1&&k1==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(k4==1&&k1==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	return 0;
}
