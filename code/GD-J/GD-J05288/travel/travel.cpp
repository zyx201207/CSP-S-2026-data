#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,b,c2,d;
	cin>>c1>>b>>c2>>d;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0000;
		return  0;
	}
	string s1,s2;
	s1=b.substr(0,2);
	s2=d.substr(0,2);
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<000;
		return 0;
	}
	int n=0;
	string p1,p2;
	p1=b.substr(2,1);
	p2=d.substr(2,1);
	if(p1=="D" || p2=="F") n=1;
	if(p1!="D" && p1!="F" ){
		if(p2=="D" || p2=="F"){
			cout<<00;
			return 0;
		}
		else{
			cout<<1;
		}
	}
	else if(p1=="D"|| p1=="F"){
		if(p2!="D" && p2!="F"){
			cout<<00;
			return 0;
		}
		else{
			cout<<1;
		}
	}
	else{
		cout<<1;
	}
	if(n==1){
		cout<<1;
	}
	if(n==0){
		if(p1=="B" || p2=="B"){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	
	return 0;
} 
