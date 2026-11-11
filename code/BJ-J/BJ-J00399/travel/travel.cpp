#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f(char c,char c2){
    if(c=='A')return c2=='B'||c2=='C';
    if(c=='B')return c2=='A'||c2=='C';
    if(c=='C')return c2=='A'||c2=='B';
    if(c=='D')return c2=='F';
    return c2=='D';
}
bool f2(char c,char c2){
    if(c=='A')return c2=='B';
    if(c=='B')return c2=='A'||c2=='C';
    if(c=='C')return c2=='B';
    if(c=='D')return c2=='F';
    return c2=='D';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s2,c,c2;
    cin>>c>>s>>c2>>s2;
    if(c!=c2){
        cout<<"0000";
        return 0;
    }
    if(s.substr(0,2)!=s2.substr(0,2)){
        cout<<"1000";
        return 0;
    }
    if(!f(s[2],s2[2])){
        cout<<"1100";
        return 0;
    }
    if(!f2(s[2],s2[2])){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}