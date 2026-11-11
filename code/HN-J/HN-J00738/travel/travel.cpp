#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,s1,t1;
	cin>>s>>s1>>t>>t1;
	for(int i=0;i<=1;i++){
		if(s[i]!=t[i]){
			cout<<"0000";
			return 0;
		}
	}	
	for(int i=0;i<=1;i++){
		if(s1[i]!=t1[i]){
			cout<<"1000";
			return 0; 
		}
	}
	if((s1[2]>='A'&&s1[2]<='C'&&t1[2]>='A'&&t1[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&t1[2]>='D'&&t1[2]<='F')){
		cout<<"111";
	}
	else{
		cout<<"1100";
		return 0;
	}
	if((s1[2]=='A'&&t1[2]=='B')||(s1[2]=='B'&&t1[2]=='A')||(s1[2]=='B'&&t1[2]=='C')||(s1[2]=='C'&&t1[2]=='B')||(s1[2]=='D'&&t1[2]=='F')||(s1[2]=='F'&&t1[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
