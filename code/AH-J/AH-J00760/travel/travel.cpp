#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,c3,c4;
bool checkcx(string s1,string s2){
    for(ll i=0;i<2;i++){
        if(s1[i]!=s2[i])    return 0;
    }
    return 1;
}
bool checkyp(string s1,string s2){
    for(ll i=0;i<2;i++){
        if(s1[i]!=s2[i])    return 0;
    }
    if(!checkcx(c1,c3)) return 0;
    return 1;
}
bool checkyc(string s1,string s2){
    if(checkcx(c1,c3)&&checkyp(c2,c4)&&'A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'||checkcx(c1,c3)&&checkyp(c2,c4)&&'D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')  return 1;
    return 0;
}
bool checkxl(string s1,string s2){
    if(!checkcx(c1,c3)||!checkyp(c2,c4)||!checkyc(c2,c4))   return 0;
    if(s1[2]=='D'||s2[2]=='D')  return 1;
    if(s2[2]==s1[2]+1||s1[2]==s2[2]+1)  return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(checkcx(c1,c3))    cout<<1;
    else cout<<0;
    if(checkyp(c2,c4))    cout<<1;
    else cout<<0;
    if(checkyc(c2,c4))    cout<<1;
    else cout<<0;
    if(checkxl(c2,c4))    cout<<1;
    else cout<<0;
    return 0;
}
