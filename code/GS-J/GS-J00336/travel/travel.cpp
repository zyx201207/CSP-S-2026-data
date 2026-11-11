#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int a=0,b=0,z1[2]={0},z2[2]={0};
    cin>>a>>z1[2]>>b>>z2[2];
	if(a=b)cout<<"1";
	else cout<<"0";
	if(a=b&&z1[0]==z2[0]&&z2[1]==z1[1])cout<<"1";
	else cout<<"0";	
	if(a=b&&z1[0]==z2[0]&&z2[1]==z1[1]&&z1[2]=='A'&&z2[2]=='B'||
	   z1[2]=='B'&&z2[2]=='A'||z1[2]=='C'&&z2[2]=='B'||
	   z1[2]=='B'&&z2[2]=='C'||z1[2]=='A'&&z2[2]=='C'||
	   z1[2]=='C'&&z2[2]=='A'||z1[2]=='D'&&z2[2]=='F'||
	   z1[2]=='F'&&z2[2]=='D')cout<<"1";
	else cout<<"0";
	if(a=b&&z1[0]==z2[0]&&z2[1]==z1[1]&&z1[2]=='A'&&z2[2]=='B'||
	   z1[2]=='B'&&z2[2]=='A'||z1[2]=='C'&&z2[2]=='B'||
	   z1[2]=='B'&&z2[2]=='C'||z1[2]=='D'&&z2[2]=='F'||
	   z1[2]=='F'&&z2[2]=='D')cout<<"1";
	else cout<<"0";
	return 0;
}
