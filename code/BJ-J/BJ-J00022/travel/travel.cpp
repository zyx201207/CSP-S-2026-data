#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],c2[2],s1[3],s2[3];
	cin>>c1[0]>>c1[1];
	cin>>s1[0]>>s1[1]>>s1[2];
	cin>>c2[0]>>c2[1];
	cin>>s2[0]>>s2[1]>>s2[2];
	int as1=0,as2=0,as3=0,as4=0;
	
	if (c1[0]==c2[0]&&c1[1]==c2[1]){
		
		as1=1;
	}else{
		as1=0;
	}if (as1==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		as2=1;
	}else{
		as2=0;
	}if (as2==1&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))){
		as3=1;
	}else{
		as3=0;
	}if (as3==1&&((abs(s2[2]-s1[2])==1&&s2[2]!='D'&&s1[2]!='D')||((s2[2]=='D'&&s1[2]=='F')||(s2[2]=='F'&&s1[2]=='D')))){
		as4=1;
	}cout<<as1<<as2<<as3<<as4;
	return 0;
}
