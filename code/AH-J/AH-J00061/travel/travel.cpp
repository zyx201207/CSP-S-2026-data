#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>a2>>s2;
    if(a1[0]-'0'*10+a1[1]-'0'==a2[0]-'0'*10+a2[1]-'0') {
        cout<<1;
    }
    else {
        cout<<"0000";
        return 0;
    }
    if(s1[0]-'0'*10+s1[1]-'0'==s2[0]-'0'*10+s2[1]-'0') {
        cout<<1;
    }
    else {
        cout<<"000";
        return 0;
    }
    if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
        cout<<1;
    }
    else {
        cout<<0;
    }
    return 0;
}
