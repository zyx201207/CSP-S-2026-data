#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool k=1;
    int s=0;
    string a1,a2,s1,s2;
    cin>>a1>>a2>>s1>>s2;
    if(a1==s1)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }


    if(a2[0]==s2[0] && a2[1]==s2[1])cout<<1;
    else {
        cout<<0;
        k=0;
    }
    if(a2[2]=='F'){
        if(s2[2]=='F')cout<<10;
        else if(s2[2]=='D' && k)cout<<11;
        else cout<<"00";
    }
    else if(a2[2]=='D'){
        if(s2[2]=='D')cout<<10;
        else if(s2[2]=='F' && k)cout<<11;
        else cout<<"00";
    }
    else if(a2[2]=='A'){
        if(s2[2]=='A' || s2[2]=='C')cout<<10;
        else if(s2[2]=='B' && k)cout<<11;
        else cout<<"00";
    }
    else if(a2[2]=='C'){
        if(s2[2]=='A' || s2[2]=='C')cout<<10;
        else if(s2[2]=='B' && k)cout<<11;
        else cout<<"00";
    }
    else if(a2[2]=='B'){
        if(s2[2]=='A' && k || s2[2]=='C' && k)cout<<11;
        else if(s2[2]=='B')cout<<10;
        else cout<<"00";
    }


return 0;
}

