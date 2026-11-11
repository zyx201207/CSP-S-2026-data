#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0] or s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char a=s1[2],b=s2[2];
	int a1,a2;
	if(a=='D' or a=='F'){
		a1=1;
	}else{
		a1=2;
	}
	if(b=='D' or b=='F'){
		a2=1;
	}else{
		a2=2;
	}
	if(a1!=a2){
		cout<<"00"; 
		return 0;
	}
	cout<<1;
	if(abs(a-b)==1){
		cout<<1;
	}else{
		cout<<0;
	}	
	return 0;
} 
