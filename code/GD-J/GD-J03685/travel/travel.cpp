#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
	string a1,s1,a2,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int aa=(s1[0]-'0')*10+s1[1]-'0';
	int bb=(s2[0]-'0')*10+s2[1]-'0';
	if(aa==bb) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='C'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='C'||s2[2]=='B')){
		cout<<1;
	}else
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
