#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]!='D') s1[2]-='A';
	else s1[2]=s1[2]-'A'+1;
	if(s2[2]!='D') s2[2]-='A';
	else s2[2]=s2[2]-'A'+1; 
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(!(s1[0]==s2[0])||!(s1[1]==s2[1])){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(s1[2]<=3){
		if(s2[2]>3){
			cout<<"00";
			return 0;
		}
		cout<<"1"; 
	}
	if(s1[2]>3){
		if(s2[2]<=3){
			cout<<"00";
			return 0;
		}
		cout<<"1"; 
	}
	if(abs(s1[2]-s2[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
} 
