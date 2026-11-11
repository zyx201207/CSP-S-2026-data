#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,s1[5],c2,s2[5],a,b,c,d;
cin>>c1>>s1[5]>>c2>>s2[5]>>a>>b>>c>>d;
int ture=1,flase=0;
if(c1!=c2){a=flase;}
else{a=ture;}
if(c1==c2){for(int i=1;i<=s1;i++){
    for(int j=1;j<=s2;j++){
    if(s1[i]==s2[j]){b=ture;}
    else{b=flase;}}}
}
if(c1==c2){for(int i=1;i<=s1;i++){
    for(int j=1;j<=s2;j++){
    if(s1[2]=='C'&&s2[2]=='D'){c=flase;}
    else{c=flase;}}}
}
if(c1==c2){for(int i=1;i<=s1;i++){
    for(int j=1;j<=s2;j++){
    if(i<j){
    if(i==j-1){d=ture;}
    else{d=flase;}}
    else if(i>=j){
    if(i=j+1){d=ture;}
    else(d=flase;)
    }}}
}
cout<<a<<b<<c<<d;
return o;
}
