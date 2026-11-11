#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){   //≥µœ· 
		cout<<"1";
	}else cout<<"0";
	string a="",b="";
	a+=s1[0];a+=s1[1];b+=s2[0];b+=s2[1];
	cout<<(a==b&&c1==c2);//≈≈ 
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&c1==c2&&a==b){//≤‡ 
		cout<<"1";
	}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&c1==c2&&a==b){
		cout<<"1";
	}else cout<<"0";
	if(a==b&&c1==c2){
		if(s1[2]=='A'&&s2[2]=='B') cout<<"1";
		else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) cout<<"1";
		else if(s1[2]=='C'&&s2[2]=='B') cout<<"1";
		else if(s1[2]=='E'&&s2[2]=='F') cout<<"1";
		else if(s1[2]=='F'&&s2[2]=='E') cout<<"1";
		else cout<<0;
	}else cout<<0;
} 
