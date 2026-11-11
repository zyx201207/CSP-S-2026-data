#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1[3],s2[3]; 

	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0] &&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[2]==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
