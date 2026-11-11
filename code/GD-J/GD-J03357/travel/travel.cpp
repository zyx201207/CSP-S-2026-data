#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1,mp['B']=1,mp['C']=1,mp['D']=2,mp['F']=2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(mp[s1[2]]==mp[s2[2]]){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1 || (s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F'&&s1[2]=='D')){
		cout<<"1";
	}
	else{
		cout<<"0"; 
	}
	return 0;
} 
