#include<iostream>
#include<string>

using namespace std;
int a1,a2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	char c1=s1[s1.length()-1],c2=s2[s2.length()-1];
	//是否都在同侧 
    if(c1<='C'&&c2<='C'||(c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))cout<<1;
    else{
    	cout<<"00";
    	return 0;
	}
	//是否相邻 
	if((c1<='C'&&c2<='C'&&(c1=='B'||c2=='B'))||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')))cout<<1;
	else{
    	cout<<"0";
    	return 0;
	}
	return 0;
}
