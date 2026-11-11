#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    char c,s,c1,s1;
    cin>>c>>s>>c1>>s1;
    if(c==c1)cout<<"1";
    else cout<<"0";
    if(c==c1){
        if((s-s%100)/100==(s1-s1%100)/100){
            cout<<"1";
        }else cout<<"0";
    }
    if(c==c1){
        if(s-s%100==s1-s1%100&&(s%100=='A'-'0'||s%100=='B'-'0'||s%100=='C'-'0')&&(s1%100=='A'-'0'||s1%100=='B'-'0'||s1-s1%100=='C'-'0')){
            cout<<"1";
        }else if(s-s%100==s1-s1%100&&(s%100=='D'-'0'||s%100=='F'-'0')&&(s1%100=='D'-'0'||s1%100=='F'-'0'))
            cout<<"1";
        else cout<<"0";
    }
    cout<<"0";
    return 0;
}
