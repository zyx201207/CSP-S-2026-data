#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int ans=0,m1=0,n1=0,m2=0,n2=0;
	string c1,c2, s1,s2,a="0000";
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=s1.size();i++){
		for(int j=0;j<=s2.size();j++){
if(c1==c2){
	a[0]='1';
}else{
	a="0000";
	break;
}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		a[1]='1';
		}else{
			a="1000";
			break;
		}
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F') ){	
		a[2]='1';
		 }else{
		 	a[2]='0';
	}
		 	
	if((s1[2]=='A' &&s2[2]=='B') ||(s1[2]=='B' && (s2[2]=='B' || s2[2]=='C')) ||(s1[2]=='C' && s2[2]=='B')||(s1[2]=='D' && s2[2]=='F')){
	a[3]='1';
	}else{
		a[3]='0';
		}
}
}
cout<<a;
return 0;
}

