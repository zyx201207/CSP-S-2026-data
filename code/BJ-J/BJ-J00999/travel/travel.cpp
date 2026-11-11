#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    int p1,p2;
    p1=(s1[0]-'0')*10+(s1[1]-'0');
    p2=(s2[0]-'0')*10+(s2[1]-'0');
    if(p1!=p2){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    bool b1,b2;
    b1=(s1[2]<='C'?0:1);
    b2=(s2[2]<='C'?0:1);
    if(b1!=b2){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(b1==1) cout<<"1";
    else if(abs(s1[2]-s2[2])==1) cout<<"1";
    else cout<<"0";
    return 0;
}