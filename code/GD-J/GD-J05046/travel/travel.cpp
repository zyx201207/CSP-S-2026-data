#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	} 
	int a=(s2[0]-'0')*10+(s2[1]-'0');
	int b=(s4[0]-'0')*10+(s4[1]-'0');
	cout<<"1";
	if(a!=b){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char c=s2[2],d=s4[2];
	if((c=='F'&&d=='D')||(c=='D'&&d=='F')||(c=='A'&&d=='B')||(c=='A'&&d=='C')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='A')||(c=='C'&&d=='B')){
		cout<<"1";
		if((c=='F'&&d=='D')||(c=='D'&&d=='F')||(c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')){
		cout<<"1";	
		return 0;	
		}else{
			cout<<"0";
			return 0;
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0; 
} 
