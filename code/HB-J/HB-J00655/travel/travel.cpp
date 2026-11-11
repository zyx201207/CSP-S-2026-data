#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    if(a2[0]!=b2[0]||a2[1]!=b2[1]){
        cout<<"1000";
        return 0;
    }
    if((a2[2]<='C'&&b2[2]>='D')||(a2[2]>='D'&&b2[2]<='C')){
        cout<<"1100";
        return 0;
    }
    if(abs(a2[2]-b2[2])!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
