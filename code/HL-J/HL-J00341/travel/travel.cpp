#include<bits/stdc++.h>
using namespace std;
string a;
string ah;
string b;
string bh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int numa=0,numb=0;
	cin>>a>>ah>>b>>bh;
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<=1;i++){
		if(ah[i]!=bh[i]){
			cout<<"1000";
			return 0;
		}
	}
	
	int apd,bpd;
	
	if(ah[2]=='A'||ah[2]=='B'||ah[2]=='C'){
		apd=1;
	}
	else{
		apd=2;
	}
	if(bh[2]=='A'||bh[2]=='B'||bh[2]=='C'){
		bpd=1;
	}
	else{
		bpd=2;
	}
	if(bpd!=apd){
		cout<<"1100";
		return 0;
	}
	if(bh[2]-1!=ah[2]&&bh[2]+1!=ah[2]){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0; 
} 
