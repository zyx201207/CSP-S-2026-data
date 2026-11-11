#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c,C,s,S,q=0,p=0;
    string a,b;
    cin>>c>>s>>a;
    cin>>C>>S>>b;
    if(c==C)
        cout<<'1';
    else{
        cout<<"0000";
        return 0;}
    if(s==S)
        cout<<'1';
    else{
        cout<<"000";return 0;
    }
    if(a=="A"||a=="B"||a=="C")
        q=1;
    else{
        q=0;
    }
    if(b=="A"||b=="B"||b=="C")
        p=1;
    else{
        p=0;
    }
    if(q==p)
        cout<<'1';
    else{
        cout<<"00";
        return 0;
        }
    if(a=="A"&&b=="B"||b=="A"&&a=="B"||a=="B"&&b=="C"||b=="B"&&a=="C")
        cout<<'1';
    else{
        if(a=="D"&&b=="F"||b=="F"&&a=="D")
        cout<<'1';
        else{
            cout<<"0";
        }
    }
    return 0;
}
