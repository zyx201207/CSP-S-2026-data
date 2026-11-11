#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1;
    cin>>b1;
    cin>>a2;
    cin>>b2;
    if(a1 == a2)
        cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b1[0] == b2[0] && b1[1] == b2[1])
        cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(b1[2] <= 'C' && b1[2] >= 'A' && b2[2] <= 'C' && b2[2] >= 'A' ){
        cout<<1;
        if(b1[2] + 1 == b2[2] || b2[2] + 1 == b1[2])
            cout<<1;
        else
            cout<<0;
    }
    else if((b1[2] == 'D' || b1[2] == 'F') && (b2[2] == 'D' || b2[2] == 'F')){
        cout<<"11";
    }
    else
        cout<<"00";
    return 0;
}
