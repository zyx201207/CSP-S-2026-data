#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2)cout<<"1";
else {
cout<<"0000";return 0;}

int s=s1[0]+s1[1]-96;
int ss=s2[0]+s2[1]-96;

if(s==ss)cout<<"1";
else {
cout<<"000";return 0;}
int a=s1[2],b=s2[2];

if(a<=67&&b<=67||a>=68&&b>=68)cout<<"1";
else {
cout<<"00";return 0;}

if(abs(a-b)<=1||a>=68&&b>=68){
	if(a==68&&b==67||b==68&&a==67){cout<<"0";
}
else cout<<"1";
	}
	else cout<<"0";
	
		


	return 0;
} 
