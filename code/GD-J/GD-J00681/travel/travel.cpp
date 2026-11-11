#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool vis=true;
string s="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) s+="1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++) if(s1[i]!=s2[i]) vis=false;
	if(vis){
		s+="1";
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
			s+="1";
			if(int(s1[2])+1==int(s2[2])||int(s1[2])+1==int(s2[2])) s+="1";
			else s+="0";
		}
		else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
			s+="1";
			if(int(s1[2])+1==int(s2[2])||int(s1[2])+1==int(s2[2])) s+="1";
			else s+="0";
		}
		else s+="00";
	}
	else s+="000";
	cout<<s;
	return 0;
} 
