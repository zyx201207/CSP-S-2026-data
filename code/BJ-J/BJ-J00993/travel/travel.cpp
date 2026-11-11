#include<bits/stdc++.h>
using namespace std;
string s,s1;
string a,a1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>a;
    cin>>s1>>a1;
    if(s!=s1){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(a[0]!=a1[0] || a[1]!=a1[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if((a[2]<='C' && a1[2]>='D') || (a[2]>='D' && a[1]<='C')){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if((a[2]=='C' && a1[2]=='A') || (a[2]=='A' && a1[2]=='C')){
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
}
