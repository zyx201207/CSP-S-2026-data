#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(!(s2[1]==s4[1]&&s2[0]==s4[0])){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(s2[2]=='D'||s2[2]=='F'){
		if(s4[2]=='D'||s4[2]=='F') cout<<"11";
		else cout<<"00";
		return 0;
	}
	else{
		if(s4[2]=='D'||s4[2]=='F') cout<<"00";
		else{
			cout<<1;
			if(s2[2]=='A'){
				if(s4[2]=='B') cout<<1;
				else cout<<0;
			}
			if(s2[2]=='B'){
				cout<<1;
			}
			if(s2[2]=='C'){
				if(s4[2]=='B') cout<<1;
				else cout<<0;
			}
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
} 
