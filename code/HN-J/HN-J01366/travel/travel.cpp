#include<bits/stdc++.h> 
using namespace std;
bool a,b,c,d;
string che1,che2,zuo1,zuo2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>zuo1>>che2>>zuo2; 
	if(che1==che2) a=true;
	else a=false;
	if(zuo1[1]==zuo2[1]&&zuo1[0]==zuo2[0]&&a==true) b=true;
	else b=false;
	if((((zuo1[2]=='A'||zuo1[2]=='B'||zuo1[2]=='C')&&(zuo2[2]=='A'||zuo2[2]=='B'||zuo2[2]=='C'))||((zuo1[2]=='F'||zuo1[2]=='D')&&(zuo2[2]=='F'||zuo2[2]=='D')))&&b==true) c=true;
	else  c=false;
	if(((zuo1[2]=='A'&&zuo2[2]=='B')||(zuo2[2]=='A'&&zuo1[2]=='B')||(zuo1[2]=='B'&&zuo2[2]=='C')||(zuo2[2]=='B'&&zuo1[2]=='C')||(zuo1[2]=='F'&&zuo2[2]=='D')||(zuo1[2]=='D'&&zuo2[2]=='F'))&&c==true) d=true;
	else d=false;
	if(a==true) cout<<"1";
	else cout<<"0";
	if(b==true) cout<<"1";
	else cout<<"0";
	if(c==true) cout<<"1";
	else cout<<"0";
	if(d==true) cout<<"1";
	else cout<<"0";
	return 0;
}
