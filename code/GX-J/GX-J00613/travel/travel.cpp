#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	char g1=s1[2],g2=s2[2];
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	bool s=0;
	if((g1>='A' && g1<='C' && g2>='A' && g2<='C') || (g1>='D' && g1<='F' && g2>='D' && g2<='F')) s=1;
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && s) 
	    cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	bool w=0;
	if((int)g1-(int)g2==1 || (int)g2-(int)g1==1) w=1;
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && s && w) 
	    cout<<"1";
	else{
		cout<<"0";
		return 0;
	}
    return 0;	
}
