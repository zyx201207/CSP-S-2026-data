//GZ-J00563，尚泽霖，贵阳一中李端棻中学
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans; 
int main(){
/*	freopen("travel.in","r",stdin);
	freopen("tarvel.out","w",stdout);*/
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";	
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		if(((c2[3]=='A'||c2[3]=='B'||c2[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))||((c2[3]=='D'||c2[3]=='F')&&(s2[3]=='D'||s2[3]=='F'))){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		if(c2[3]=='A'&&s2[3]=='B'){
			cout<<"1";
		}
		else if(c2[3]=='B'&&s2[3]=='A'){
			cout<<"1";
		}
		else if(c2[3]=='B'&&s2[3]=='C'){
			cout<<"1";
		}
		else if(c2[3]=='C'&&s2[3]=='B'){
			cout<<"1";
		}
		else if(c2[3]=='D'&&s2[3]=='F'){
			cout<<"1";
		}
		else if(c2[3]=='F'&&s2[3]=='F'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
