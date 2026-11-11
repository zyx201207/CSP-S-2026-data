#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	string t1;
	t1=s2[0]+s2[1];
	string t2;
	t2=s4[0]+s4[1];
	char h1=s2[2],h2=s4[2];
	if(s1==s3){
		cout<<"1";
		if(t1==t2){
			cout<<"1";
			if(h1>='A'&&h2>='A'&&h1<='C'&&h2<='C'||h1>='D'&&h2>='D'&&h1<='F'&&h2<='F'){
				cout<<"1";
				if(h1+1==h2||h1-1==h2)cout<<"1";
				else cout<<"0"; 
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
