#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;cin>>a;string b;cin>>b;string c;cin>>c;string d;cin>>d;
    if(a[0]==c[0]){
        if(a[1]==c[1]){
            cout<<1;
        }else{
            cout<<"0000";return 0;
        }
    }else{
        cout<<"0000";return 0;
    }if(b[0]==d[0] and b[1]==d[1]){
        cout<<1;
    }else{
        cout<<"000";return 0;
    }if(b[2]=='A' or b[2]=='B' or b[2]=='C'){
        if(d[2]=='A' or d[2]=='B' or d[2]=='C'){
            cout<<1;
            if(b[2]=='A' and d[2]=='C'){
                cout<<0;return 0;
            }if(b[2]=='C' and d[2]=='A'){
                cout<<0;return 0;
            }cout<<1; return 0;
        }else{
            cout<<"00";
        }
    }if(b[2]=='D' or b[2]=='E'){
        if(d[2]=='D' or d[2]=='E'){
            cout<<11;
        }else{
            cout<<"00";
        }
    }

}