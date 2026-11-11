#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;


    if(a1==b1)cout<<1;
    else cout<<0;


    if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1])cout<<1;
    else cout<<0;


    if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && a2[2]=='A'){
        if(b2[2]=='B' || b2[2]=='C')cout<<1;
        else cout<<0;
    }
    else if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && a2[2]=='B'){
        if(b2[2]=='A' || b2[2]=='C')cout<<1;
        else cout<<0;
    }
    else if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && a2[2]=='C'){
        if(b2[2]=='B' || b2[2]=='A')cout<<1;
        else cout<<0;
    }
    else if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && a2[2]=='D'){
        if(b2[2]=='F')cout<<1;
        else cout<<0;
    }
    else if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && a2[2]=='F'){
        if(b2[2]=='D')cout<<1;
        else cout<<0;
    }
    else cout<<0;


    if((a1==b1 && a2[0]==b2[0] && a2[1]==b2[1]) && (a2[2]=='A' && b2[2]=='B' || a2[2]=='B' && b2[2]=='A' || a2[2]=='B' && b2[2]=='C' || a2[2]=='C' && b2[2]=='C' || a2[2]=='D' && b2[2]=='F' || a2[2]=='F' && b2[2]=='D'))cout<<1;
    else cout<<0;
    return 0;
}