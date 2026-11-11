#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	bool pd=false;
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]) pd=true;
		else pd=false;
	}
	if(pd==true) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	
	if((s1[2]=='A'&&s2[2]=='D')||(s1[2]=='B'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='F')||(s1[2]=='C'&&s2[2]=='F')){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	
	return 0;
}
