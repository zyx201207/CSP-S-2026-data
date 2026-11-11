#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	//ABC | DF
	bool t1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
	bool t2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&t1==t2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&t1==t2&&abs(s1[2]-s2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
