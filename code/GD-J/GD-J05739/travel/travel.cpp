#include<bits/stdc++.h>
using namespace std;
long long a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]-'0'==s2[0]-'0' and s1[1]-'0'==s2[1]-'0'){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='F' or s1[2]=='D'){
		if(s2[2]=='F' or s2[2]=='D'){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(s1[2]-'0'==s2[2]-'0'+1 or s1[2]-'0'==s2[2]-'0'-1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
