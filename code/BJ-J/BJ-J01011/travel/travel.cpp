#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1.substr(0,2)==s2.substr(0,2))cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char st1=s1[2],st2=s2[2];
    if(!((st1<='C')^(st2<='C')))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(st1+1==st2||st2+1==st1)cout<<1;
    else cout<<0;
    return 0;
}