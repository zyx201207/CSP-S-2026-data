#include<bits/stdc++.h>
using namespace std;
int zh(string s){
	return (s[0]-'0')*10+s[1]-'0';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
    	cout<<"0000";
    	return 0;
	}
	cout<<1;
	int ch1=zh(s1.substr(0,2)),ch2=zh(s2.substr(0,2));
	if(ch1!=ch2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(s1[2]>s2[2]){
		swap(s1,s2);
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s2[2]-s1[2]>1){
		cout<<0;
	}
	else{
		cout<<1;
	}
}
