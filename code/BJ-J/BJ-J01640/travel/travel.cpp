#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,c2,s1,s2;
int flag=0;
cin>>c1>>c2>>s1>>s2;
for(int i=0;i<2;i++){
    if(c1[i]!=s1[i]) flag=1;
    }
if(flag) {cout<<"0000";
    return 0;
    }else{
    cout<<"1";}
if(s1[1]==s2[1]&&s1[0]==s2[0]){
cout<<"1";}
else {cout<<"0";}
if(c2[2]=='A'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='A'||c2[2]=='A'&&s2[2]=='C'||c2[2]=='C'&&s2[2]=='A'||c2[2]=='C'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='C'||c2[2]=='D'&&s2[2]=='F'||c2[2]=='F'&&s2[2]=='D'){
cout<<"1";}
else {cout<<"0";}
if(c2[1]==s2[1]&&c2[0]==s2[0]&&(c2[2]=='A'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='C'||c2[2]=='D'&&s2[2]=='F'||c2[2]=='F'&&s2[2]=='D')){
cout<<"1";}
else {cout<<"0";}
cout<<endl;
return 0;
}