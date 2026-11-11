#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000\n";
        return 0;
    }
    else
        cout<<'1';
    char c1=a2[0],c2=b2[0],d1=a2[1],d2=b2[1];
    if((c1!=c2) || (d1!=d2)){
        cout<<"000\n";
        return 0;
    }
    else
        cout<<'1';
    char x=a2[2],y=b2[2];
    if(((x=='A' || x=='B' || x=='C') && (y=='D' || y=='F')) || ((y=='A' || y=='B' || y=='C') && (x=='D' || x=='F'))){
        cout<<"00\n";
        return 0;
    }
    else
        cout<<'1';
    if((x=='A' && y=='B') || (x=='B' && y=='A') || (x=='B' && y=='C') || (x=='C' && y=='B') || (x=='D' && y=='F') || (x=='F' && y=='D')){
        cout<<"1\n";
        return 0;
    }
    else
        cout<<'0';
    return 0;
}
