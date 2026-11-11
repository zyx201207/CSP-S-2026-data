#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,out1,t1,t2;

void check(){
	if(c1==c2)out1+="1";
	else {out1="0000";return;}
	
	t1+=s1[0];t1+=s1[1];
	t2+=s2[0];t2+=s2[1];
	if(t1==t2)out1+="1";
	else {out1+="000";return;}
	
	if( ((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) || ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) )out1+="1";
	else {out1+="00";return;}
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		out1+="1";
    }
    else{out1+="0";return;}
    
    return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	check();
	cout<<out1<<endl;
return 0;
}
