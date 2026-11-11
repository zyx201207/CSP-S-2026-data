#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"1000";
        return 0;
    }
    if((b[2]=='D'&&d[2]!='F')||(b[2]=='F'&&d[2]!='D')||(d[2]=='D'&&b[2]!='F')||(d[2]=='F'&&b[2]!='F')){
        cout<<"1100";
        return 0;
    }
    if(abs(b[2]-d[2])!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}