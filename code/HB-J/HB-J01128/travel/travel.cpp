#include<bits/stdc++.h>
using namespace std;
string a1,a2;
char b11,b21,b12,b22,b13,b23;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>b11>>b12>>b13>>a2>>b21>>b22>>b23;
    if(a1==a2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(b11==b21&&b12==b22){
        cout<<1;
    }
    else {
        cout<<"000";
        return 0;
    }
    if(((b13=='A'||b13=='B'||b13=='C')&&(b23=='A'||b23=='B'||b23=='C'))||((b13=='D'||b13=='F')&&(b23=='D'||b23=='F'))){
        cout<<1;
    }
    else {
        cout<<"00";
        return 0;
    }
    if((abs(int(b13-b23))==1)||(b13=='F'&&b23=='D')||(b13=='D'&&b23=='F'))cout<<1;
    else {
        cout<<"0";
    }
    return 0;
}
