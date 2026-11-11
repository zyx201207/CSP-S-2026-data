#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int chex1=0,chex2=0,pshu1=0,pshu2=0;
	char lshu1=a2[2],lshu2=b2[2];
	for(int i=0;i<a1.size();i++){
		chex1=chex1*10+a1[i]-'0';
	}
	for(int i=0;i<b1.size();i++){
		chex2=chex2*10+b1[i]-'0';
	}
	for(int i=0;i<a2.size()-1;i++){
		pshu1=pshu1*10+a2[i]-'0';
	}
	for(int i=0;i<b2.size()-1;i++){
		pshu2=pshu2*10+b2[i]-'0';
	}
	if(chex1!=chex2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if(pshu1!=pshu2){
		cout<<"000";
		return 0;
	}else{
		cout<<1;
	}
	if((lshu1<='C'&&lshu2<='C')||(lshu1>='D'&&lshu2>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs((int)lshu1-(int)lshu2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
