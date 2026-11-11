#include <bits/stdc++.h>
using namespace std;
int main(){
char c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1!=c2){
cout<<"0000";
return 0;}
else{
    cout<'1';
}
if(c1[1]==c2[1] oand c1[2] == c2[2]){
    cout<<'1';
}
else{
    cout<<'000';
    return 0;
}
if((c1[3]>='C' and c2[3]>='C') or (c1[3]<='C' and c2[3]<='C') ){
    cout<<'1';
}
else{
    cout<<"00";
    return 0;}
if(c1[3]-c2[3]==1 or c2[3]-c1[3]){
    cout<<"1";
    return 0;
}
cout<<'0';
return 0;
}