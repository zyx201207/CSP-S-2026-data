#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool t;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    else {
        cout<<1;
        if(a2[1]==b2[1]) cout<<1;
        else cout<<0;
        if(a2[1]==b2[1]&&((a2[2]>='E'&&a2[2]<='F'&&b2[2]>='E'&&b2[2]<='F')||(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'))){
        cout<<1;
        t=true;
        }
        else cout<<0;
        if(t!=true||(t==true&&(a2[2]=='A'&&b2[2]=='C')||(b2[2]=='A'&&a2[2]=='C'))) cout<<0;
        else cout<<1;
    }
    return 0;
}
