#include <bits/stdc++.h>
using namespace std;
string a1,s1;
string a2,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a1>>s1>>a2>>s2;
if(a1==a2){
    cout<<"100";
}
if(s1==s2){
    cout<<"0000";
}
else{
    cout<<"0";
}

return 0;}
