#include<bits/stdc++.h>
using namespace std;
string gycc1,gycc2;
char gycs1[3],gycs2[3];
int ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>gycc1;
	for(int i=0;i<=2;i++){
		cin>>gycs1[i];
	}
	cin>>gycc2;
	for(int i=0;i<=2;i++){
		cin>>gycs2[i];
	}
	if(gycc1==gycc2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	ss1=int(gycs1[0]-'0')*10+int(gycs1[1]-'0');
	ss2=int(gycs2[0]-'0')*10+int(gycs2[1]-'0');
	if(ss1==ss2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((gycs1[2]=='A'||gycs1[2]=='B'||gycs1[2]=='C')&&(gycs2[2]=='A'||gycs2[2]=='B'||gycs2[2]=='C')){
		cout<<1;
		if(abs(int (gycs1[2]-gycs2[2]))==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((gycs1[2]=='F'||gycs1[2]=='D')&&(gycs2[2]=='F'||gycs2[2]=='D')){
		cout<<11;
	}else{
		cout<<"00";
		return 0;
	}
	 
	return 0;
}
