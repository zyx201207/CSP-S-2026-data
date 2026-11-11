#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0; 
		}
	}
	cout<<"1";
	for(int j=0;j<2;j++){
		if(s1[j]!=s2[j]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[2]=='D'&&s2[2]=='F'){
		cout<<"11";
		return 0;
	}
	else if(s1[2]=='A'&&s2[2]=='B'||'C'){
		cout<<"1";
		if(s2[2]=='B'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	else if(s1[2]=='B'&&s2[2]=='A'||'C'){
		cout<<"11";
		return 0;
	}
	else if(s1[2]=='C'&&s2[2]=='B'||'A'){
		cout<<"1";
		if(s2[2]=='B'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	return 0;
} 
