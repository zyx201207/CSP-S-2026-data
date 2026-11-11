#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) cout<<1;
		else {
			cout<<00;
			return 0;
		}
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]<='C'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1)||s1[2]>='D'&&s2[2]>='D') cout<<1;
		else cout<<0;
	}
	return 0;	
}