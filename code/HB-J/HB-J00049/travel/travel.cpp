#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rr1,rr2,xx1,xx2;
    cin>>rr1>>rr2>>xx1>>xx2;
    if(rr1!=xx1) {cout<< "0000"; return 0;}
    else if(rr2[0]!=xx2[0] || rr2[1]!=xx2[1]){cout<<"1000"; return 0;}
    else if(rr2[2]<=67 && xx2[2]<=67){
        if(rr2[2]-xx2[2]==1 || xx2[2]-rr2[2]==1){cout<<"1111"; return 0;}
        else{cout<<"1110"; return 0;}
    }
    else {
        if(max(rr2[2],xx2[2])==70 && min(rr2[2],xx2[2])==69){cout<<"1111"; return 0;}
        else{cout<<"1100"; return 0;}
    }

    return 0;
}
