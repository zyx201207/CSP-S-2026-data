#include<bits/stdc++.h>
using namespace std;
map<char,int>mp1={
    {'A',0},
    {'B',0},
    {'C',0},
    {'D',1},
    {'F',1}
};
map<char,int>mp2={
    {'A',0},
    {'B',1},
    {'C',2},
    {'D',4},
    {'F',5}
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else{cout<<"0000";return 0;}
    if(s1.substr(0,2)==s2.substr(0,2))
        cout<<1;
    else{cout<<"000";return 0;}
    if(mp1[s1[2]]==mp1[s2[2]])
        cout<<1;
    else cout<<0;
    if(s2.substr(0,1)==s2.substr(0,2)
       &&abs(mp2[s1[2]]-mp2[s2[2]]) ==1)
        cout<<1;
    else cout<<0;
    return 0;
}
