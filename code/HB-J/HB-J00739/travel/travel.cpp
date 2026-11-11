#include<bits/stdc++.h> 
using namespace std; 
string c1,c2,s1,s2;
bool pan1(){ return c1==c2; } 
bool pan2(){ for(int i=0;i<=1;i++)if(s1[i]!=s2[i])return 0; return 1; }
bool pan3(){
int x,y; 
if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')x=1; else x=2; 
if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')y=1; else y=2;
return x==y; 
} 
bool pan4(){ return max(s1[2],s2[2])-min(s1[2],s2[2])==1; } 
int main(){ 
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2; 
if(!pan1()){cout<<"0000";return 0;} 
if(!pan2()){cout<<"1000";return 0;} 
if(!pan3()){cout<<"1100";return 0;} 
if(!pan4()){cout<<"1110";return 0;} 
cout<<"1111"; 
return 0; 
}
