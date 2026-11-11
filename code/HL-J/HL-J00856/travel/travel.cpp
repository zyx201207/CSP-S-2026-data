#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    string c1,s1,c2,s2,a,b;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
    	cout<<0;cout<<0;cout<<0;cout<<0;
    	return 0;
	}
    for(int i=0;i<s1.size();i++){
    	if(s1[i]>='1'&&s1[i]<='9'){
    		a+=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
    	if(s2[i]>='1'&&s2[i]<='9'){
    		b+=s2[i];
		}
	}
	if(a==b) cout<<1;
	else{
    	cout<<0;cout<<0;cout<<0;
    	return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') cout<<1;
	else{
    	cout<<0;cout<<0;
    	return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') cout<<1;
	else{
    	cout<<0;
    	return 0;
	}
    return 0;
}
