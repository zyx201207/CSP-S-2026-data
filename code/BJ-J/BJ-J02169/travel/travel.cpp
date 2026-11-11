//100pts
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
string sd1,sd2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    s1=" "+s1;
    s2=" "+s2;
    sd1=s1[1]+s1[2];
    sd2=s2[1]+s2[2];
    if(sd1!=sd2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='D'||s2[3]=='E'))||((s1[3]=='D'||s1[3]=='E')&&(s2[3]=='A'||s2[3]=='B'||s1[3]=='C'))){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(abs((int)s1[3]-(int)s2[3])!=1){
        cout<<"0";
        return 0;
    }
    cout<<1;
    return 0;
}
