#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool pd1=0,pd2=0,pd3=0,pd4=0;
	
	if(c1==c2){
		pd1=1;
	}else pd1=0;
	
	if(pd1 && s1[0]==s2[0] && s1[1]==s2[1]){
		pd2=1;
	}else pd2=0;
	
	if(pd2 && (( (s1[2]=='D' || s1[2]=='F')&&(s2[2]=='D' || s2[2]=='F')) 
			|| (s1[2]=='A' || s1[2]=='B' ||s1[2]=='C')&&(s2[2]=='A' || s2[2]=='B' ||s2[2]=='C') ))pd3=1;
	else pd3=0;
	if(pd3 && (( (s1[2]=='D' || s1[2]=='F')&&(s2[2]=='D' || s2[2]=='F')) 
			|| (s1[2]=='A' || s1[2]=='B')&&(s2[2]=='A' || s2[2]=='B')
			|| (s1[2]=='B' || s1[2]=='C')&&(s2[2]=='C' || s2[2]=='B')) )pd4=1;
	else pd4=0;
	if(pd1)cout<<1;else cout<<0;
	if(pd2)cout<<1;else cout<<0;
	if(pd3)cout<<1;else cout<<0;
	if(pd4)cout<<1;else cout<<0;
	return 0;
}


