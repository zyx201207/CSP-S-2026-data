#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[3],s2[3];
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<'D'&&s2[2]<'D'){
		cout<<"1";
		if(s2[2]-s1[2]==1||s1[2]-s2[2]==1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	if(s1[2]>='D'&&s2[2]>='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	return 0;
}
