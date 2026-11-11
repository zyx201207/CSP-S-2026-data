#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char T1,T2;
	for(int i=0; i<s1.size(); i++){
		if(s1[i]>='A'&&s1[i]<='Z'){
			T1=s1[i];
			s1[i]='1';
		}
	}
	for(int i=0; i<s2.size(); i++){
		if(s2[i]>='A'&&s2[i]<='Z'){
			T2=s2[i];
			s2[i]='1';
		}
	}
	string d="0000";
	if(c1==c2){
		d[0]='1';
	}
	if(d[0]=='1'&&s1==s2){
		d[1]='1';
	}
	if(d[1]=='1'&&T1>='A'&&T1<='C'&&T2>='A'&&T2<='C'){
		d[2]='1';
	}
	if(d[1]=='1'&&(T1=='D'||T1=='F')&&(T2=='D'||T2=='F')){
		d[2]='1';
	}
	if(d[2]=='1'){
		if(abs(T1-T2)==1){
			d[3]='1';
		}
	}
	cout<<d;
	return 0;
} 
