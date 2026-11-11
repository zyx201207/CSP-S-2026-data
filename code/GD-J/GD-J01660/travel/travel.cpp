#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
//cout<<a<<bA<<c<<d;
bool cartt=(a==c?1:0);
cout<<cartt;

bool lineee;
//cout<<b[1]<<d[1];
if(b[0]==d[0]&&b[1]==d[1]&&cartt){
	lineee=1; 
}
else lineee=0;
cout<<lineee;
bool sideee=0;

if((((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E')))&&lineee){
	sideee=1;
}
cout<<sideee;
bool withhh=0;
if(sideee&&abs(int(b[2]-'a')-int(d[2]-'a'))==1)withhh=1;
cout<<withhh;
} 
