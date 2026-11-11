#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	}else{
		cout<<"0000";
		return 0;
	}
	int zw1=0,zw2=0;
	for(int i=0;i<2;i++){
		zw1=s1[i]-'0'+zw1*10;
		zw2=s2[i]-'0'+zw2*10;
	}
	if(zw1==zw2){
	}else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
		}else{
			cout<<"1100";
			return 0;
		}
	}else{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		}else{
			cout<<"1100";
			return 0;
		}
	}
	if(abs((s2[2]-'A')-(s1[2]-'A'))==1){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
	
}
