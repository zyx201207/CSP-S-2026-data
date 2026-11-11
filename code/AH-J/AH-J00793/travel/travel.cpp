#include<bits/stdc++.h>
using namespace std;
string w1,w2,v1,v2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>w1>>w2>>v1>>v2;
    if(w1==v1) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(w2[0]==v2[0]&&w2[1]==v2[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((w2[2]<='C'&&v2[2]<='C')||(w2[2]>'C'&&v2[2]>'C'))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((w2[2]=='D'&&v2[2]=='F')||(w2[2]=='F'&&v2[2]=='D')||(w2[2]=='A'&&v2[2]=='B')||(w2[2]=='B'&&v2[2]=='A')||(w2[2]=='C'&&v2[2]=='B')||(w2[2]=='B'&&v2[2]=='C')){
        cout<<1;
    }else cout<<0;
    return 0;
}
