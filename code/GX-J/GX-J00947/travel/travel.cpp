#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,s1,c2,s2;
int a=0,a1=0;
if(c1!=01,16&&c2!=01,16){
    cin>>c1>>c2;
}
cin>>s1>>s2;
if(c1==c2&c1,c2!=1,16){
    cout<<"1";
}
else{
    cout<<"0";
}
if(s1-s2>0){
    a=s1;
    a1=s2;
}
else{
    a=s2;
    a1=s1;
}

if(a-a1<=4){
    cout<<"1";
}
else{
    cout<<"0";
}
if(a-a1<=2||a-a1=1){
    cout<<"1";
}
else{
    cout<<"0";
}
if(a-a1=1){
    cout<<"1";
}
else{
    cout<<"0";
}
return 0;
}
