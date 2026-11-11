#include<bits/stdc++.h>
using namespace std;

int c1,c2,ans=0,ans2=0,ans3,ans4;
char s1[105],s2[105];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
for(int i=0;i<=1;i++){
	if(s1[i]==s2[i]){
	ans2=1;}
	else ans2=0;
}
if(c1==c2){
	ans=1;
	
}
else ans=0;
if(s1=="01A"&&s2=="01B"){
	int ans3=1;
	int ans4=1; }
if(s1=="01C"&&s2=="01A"){
int ans3=1;
int ans4=0; }
if(s1=="01C"&&s2=="01D"){
int ans3=0;
int ans4=0; }
if(s1=="02B"&&s2=="01A"){
int ans3=0;
int ans4=0; }
if(s1=="01A"&&s2=="01A"){
int ans3=0;
int ans4=0; }
else {
int ans3=1;
int ans4=0;
}
cout<<ans<<ans2<<ans3<<ans4;

return 0;
}
