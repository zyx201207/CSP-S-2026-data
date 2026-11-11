#include<bits/stdc++.h>
using namespace std;
//#define int long long
string a,b,x,y;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>x>>y;
    if(a!=x){
        cout<<"0000";
        return 0;
    }
    if(b[0]!=y[0]||b[1]!=y[1]){
        cout<<"1000";
        return 0;
    }
    if((b[2]<'D'&&y[2]>='D')||(b[2]>='D'&&y[2]<'D')){
        cout<<"1100";
        return 0;
    }
    if((b[2]=='D'&&y[2]!='F')||(b[2]=='A'&&y[2]!='B')||(b[2]=='B'&&y[2]!='C')||(b[2]=='F'&&y[2]!='D')||(b[2]=='B'&&y[2]!='A')||(b[2]=='C'&&y[2]!='B')){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
