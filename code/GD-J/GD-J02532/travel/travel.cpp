#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool pd1=false,pd2=false,pd3=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		pd1=true;
	}
	else{
		cout<<0;
	}
	if(pd1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<1;
		pd2=true;
	}
	else{
		cout<<0;
	}
	if(pd1&&pd2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<1;
		pd3=true;
	}
	else{
		cout<<0;
	}
	if(pd1&&pd2&&pd3&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
