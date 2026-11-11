#include<bits/stdc++.h>
using namespace std;
 
string a,b,c,d;
 
 int main(){
 	ios::sync_with_stdio(0);
 	cin>>a>>b>>c>>d;
 	if(a==c) cout<<"1";
 	else{
 		cout<<"0000";
 		return 0;
	} 
 	string n;
 	string m;
 	for(int i=0;i<3;++i){
 		if(i!=2) n+=b[i];
 		else m+=b[i];
	 }
	string x;
	string y;
	for(int j=0;j<3;++j){
		if(j!=2) x+=d[j];
		else y+=d[j];
	}
	if(n==x) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(m<="C"){
		if(!(y<="C")){
			cout<<"00";
			return 0;
		}
	}else{
		if(!(y<="F"&&y>"C")){
			cout<<"00";
			return 0;
		}
	}
	cout<<"1";
	if(m=="A"&&y=="B"){
		cout<<"1";
		return 0;
	} 
	if(m=="B"&&y=="C"){
		cout<<"1";
		return 0;
	} 
	if(m=="B"&&y=="A"){
		cout<<"1";
		return 0;
	} 
	if(m=="D"&&y=="F"){
		cout<<"1";
		return 0;
	}
	if(m=="F"&&y=="D"){
		cout<<"1";
		return 0;
	}
	if(m=="C"&&y=="B"){
		cout<<"1";
		return 0;
	} 
	cout<<"0";
	return 0;
 }
