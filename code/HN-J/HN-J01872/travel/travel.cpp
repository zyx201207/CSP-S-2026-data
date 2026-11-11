#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	int s=s1[2]-'A';
	int ss=s2[2]-'A';
	if(s>=0 and s<=2){
		if(ss==3 or ss==5){
			cout<<"00";
			return 0;
		}
	}else{
		if(ss>=0 and ss<=2){
			cout<<"00";
			return 0;
		}
	}
	cout<<"1";
	if(s==0 and ss==2){
		cout<<"0";
	}else if(s==2 and ss==0){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
} 
