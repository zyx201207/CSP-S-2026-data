#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=c1.size()-1;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
		cout<<"1";
		if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(s1[2]<='F'&&s1[2]>='D'&&s1[2]<='F'&&s1[2]>='D'){
		cout<<"11";
	}else{
		cout<<"00";
	}
	return 0;
} 
