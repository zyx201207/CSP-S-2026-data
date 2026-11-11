#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string ss1="";
	ss1=ss1+s2[0]+s2[1];
	string ss2="";
	ss2=ss2+s4[0]+s4[1];
	if(ss1==ss2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int t1=s2[2],t2=s4[2];
	if(t1<='C'&&t2>='D'||t2<='C'&&t1>='D'){
		cout<<"00";
		
		return 0;
	}else{
		cout<<1;
	}
	if(t1-t2==1||t2-t1==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
