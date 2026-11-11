#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	string a2="A",b2="B",c2="C",d2="D",f2="F";
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(a1[1]!=b1[1]){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	
	if((a1[2]==a2[0]||a1[2]==b2[0]||a1[2]==c2[0])&&(b1[2]==d2[0]||b1[2]==f2[0])||(b1[2]==a2[0]||b1[2]==b2[0]||b1[2]==c2[0])&&(a1[2]==d2[0]||a1[2]==f2[0])){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(a1[2]-1==b1[2]||b1[2]-1==a1[2]){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
