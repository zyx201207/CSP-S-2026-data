#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3];
	for(int i=0;i<2;++i){
		cin>>c1[i];
	}
	for(int i=0;i<3;++i){
		cin>>s1[i];
	}
	for(int i=0;i<2;++i){
		cin>>c2[i];
	}
	for(int i=0;i<3;++i){
		cin>>s2[i];
	}
	for(int i=0;i<2;++i){
		if(c1[i]-'0'!=c2[i]-'0'){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<2;++i){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='D' || s2[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
			cout<<"00";
			return 0;
		}
	}
	cout<<"1";
	if(abs(s1[2]-s2[2])==1)
	cout<<"1";
	else if(s1[2]=='D' && s2[2]=='F')
	cout<<"1";
	else if(s2[2]=='D' && s1[2]=='F')
	cout<<"1";
	else cout<<"0";
	return 0;
}
