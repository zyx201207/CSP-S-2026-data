#include<iostream>
#include<cmath>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(c[2]=='D') c[2]=E;
    if(d[2]=='D') d[2]=E;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(c[0]==d[0]&&c[1]==d[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(c[2]-'A'<=2&&d[2]-'A'<=2) cout<<1;
    else if(c[2]-'A'>2&&d[2]-'A'>2) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(int(c[2]-d[2]))==1) cout<<1;
    else cout<<0;
    return 0;
}
