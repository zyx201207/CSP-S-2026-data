#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
char t[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)t[0]='1';
	else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]==s2[0])&&(s1[1]==s2[1]))t[1]='1';
	else{
		cout<<t[0]<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C'))t[2]='1';
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))t[2]='1';
	else{
		cout<<t[0]<<t[1]<<"00";
		return 0;
	}
	int r=int(s1[2]),x=int(s2[2]);
	if(abs(r-x)==1&&(s1[2]<='C'&&s2[2]<='C'))t[3]='1';
	else if(abs(r-x)==2&&(s1[2]>='D'&&s2[2]>='D'))t[3]='1';
	else{
		cout<<t[0]<<t[1]<<t[2]<<"0";
		return 0;
	}
	for(int i=0;i<4;i++)cout<<t[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
