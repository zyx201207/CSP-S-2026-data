#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string s1,c1,c2,s2;
int a,b;
cin>>c1>>s1>>c2>>s2;
a=s1[2];
b=s2[2];
if(c1==c2){
    cout<<"1";
}
else{
    cout<<"0";
}
if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
    cout<<"1";
}
else{
    cout<<"0";
}
if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
        if((a==65&&b==66)||(a==65&&b==67)||(a==66&&b==65)||(a==66&&b==67)||(a==67&&b==65)||(a==67&&b==66)||(a==68&&b==69)||(a==69&&b==68)){
    cout<<"1";}
    else{
    cout<<"0";}
}
else{
    cout<<"0";
}
if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
        if((a==65&&b==66)||(a==65&&b==67)||(a==66&&b==65)||(a==66&&b==67)||(a==67&&b==65)||(a==67&&b==66)||(a==68&&b==69)||(a==69&&b==68)){
         if((a==65&&b==66)||(a==66&&b==65)||(a==66&&b==67)||(a==67&&b==66)||(a==68&&b==69)||(a==68&&b==69)){
    cout<<"1";
    }
    else{
        cout<<"0";
    }
    }
    else{
    cout<<"0";}
}
else{
    cout<<"0";
}
return 0;
}
