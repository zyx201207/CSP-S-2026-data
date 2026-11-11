#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int c,c1;
int numA,numB;
string s,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	numA=(s[0]-'0')*10+(s[1]-'0');
	numB=(s1[0]-'0')*10+(s1[1]-'0');
	if(numA==numB){
		cout<<"1";
		if(s[2]>='A'&&s[2]<='C'&&s1[2]>='A'&&s1[2]<='C'){
			cout<<"1";
		}
		else if(s[2]>='D'&&s[2]<='F'&&s1[2]>='D'&&s1[2]<='F'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"00";
	}
	
	if((abs(numA-numB)==1&&abs(s[2]-s1[2])==0)||(abs(numA-numB)==0&&abs(s[2]-s1[2])==1)){
		if((s[2]=='C'&&s1[2]=='D')||(s[2]=='D'&&s1[2]=='C')){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
