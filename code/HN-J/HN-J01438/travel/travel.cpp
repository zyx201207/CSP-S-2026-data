#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
     int x=0,y=0,z=0,l=0;
     int a=0,b=0,c=0,d=0;
string c1,s1,c2,s2;
cin>>c1>>c2>>s1>>s2;
if(c1==s1){
    a=1;
}
else{
    cout<<a<<b<<c<<d;
    l=1;
}
for(int i=0;i<2;i++){
    if(s1[i]!=s2[i]){
        x++;
    }
}
if(x==0){
    b=1;
}
else if(l==0){
     cout<<a<<b<<c<<d;
     l=1;

}
if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
    y++;
}
if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
    y++;
}
if(c2[2]=='D'||c2[2]=='F'){
    z++;
}
if(s2[2]=='D'||s2[2]=='F'){
    z++;
}
if(z==2||y==2){
    c=1;
    if(z==2){
        d=1;
    }
    else if(c2[2]=='B'||s2[2]=='B'){
        d=1;
    }
    else if(l==0){
         cout<<a<<b<<c<<d;
     l=1;
    }
}
else if(l==0){
     cout<<a<<b<<c<<d;
     l=1;
}
if(l==0){
cout<<a<<b<<c<<d;
}
return 0;
}
