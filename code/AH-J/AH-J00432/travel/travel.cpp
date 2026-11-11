#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool ok1=true;
bool ok2=true;
bool ok3=true;
bool ok4=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]){
			ok1=false;
		}
	}
	if(ok1==true){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			ok2=false;
		}
	}
	if(ok2==true){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C'))||(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C'))||(s2[2]=='C'&&(s4[2]=='A'||s4[2]=='B'))||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
		ok3=true;
	}else{
		ok3=false;
	}
	if(ok3==true){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s2[2]=='D'&&s4[2]=='F'){
		ok4=true;
	}
	if(s2[2]=='F'&&s4[2]=='D'){
		ok4=true;
	}
	if(s2[2]=='A'&&s4[2]=='B'){
		ok4=true;
	}
	if(s2[2]=='B'&&(s4[2]=='C'||s4[2]=='A')){
		ok4=true;
	}
	if(s2[2]=='C'&&s4[2]=='B'){
		ok4=true;
	}
	if(ok4==true){
		cout<<1;
	}else{
		cout<<0;
	}
		return 0;
}
