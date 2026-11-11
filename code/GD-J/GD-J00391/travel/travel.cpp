#include<iostream>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int snum1,snum2;
char pos1,pos2;

bool check(){
	if(pos1<='C'){
		if(pos2<='C'){
			return true;
		}else{
			return false;
		}
	}else{
		if(pos2<='C'){
			return false;
		}else{
			return true;
		}
	}
}

bool nearbyc(){
	if(pos1=='A' && pos2=='B'){
		return true;
	}
	if(pos1=='B' && pos2=='A'){
		return true;
	}
	if(pos1=='B' && pos2=='C'){
		return true;
	}
	if(pos1=='C' && pos2=='B'){
		return true;
	}
	if(pos1=='D' && pos2=='F'){
		return true;
	}
	if(pos1=='F' && pos2=='D'){
		return true;
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			snum1=snum1*10+s1[i]-'0';
		}else if(s1[i]>='A' && s1[i]<='Z'){
			pos1=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9'){
			snum2=snum2*10+s2[i]-'0';
		}else if(s2[i]>='A' && s2[i]<='Z'){
			pos2=s2[i];
		}
	}
	
	if(snum1!=snum2){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	
	if(check()==false){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	
	if(nearbyc()){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}










