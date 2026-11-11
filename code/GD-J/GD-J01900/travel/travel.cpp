#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=true;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			a=false;
		}
	}
	if(a==true){
		cout<<"1";
	}else if(a==false){
		cout<<"0000";
		return 0;
	}
	bool flag=true;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag=false;
			break;
		}
	}
	if(flag==true){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C') && (s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<"1";
	}else if((s1[2]=='D'||s1[2]=='F') && (s2[2]=='D'||s2[2]=='F')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
