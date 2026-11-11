#include <iostream>
using namespace std;
string a,as,b,bs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>as>>b>>bs;
    if(a==b)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(as[0]+as[1]==bs[0]+bs[1])cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(as[2]<='C'&&bs[2]<='C' || as[2]>='D'&&bs[2]>='D')cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(as[2]=='A'&&bs[2]=='B' || as[2]=='B'&&bs[2]=='A' || as[2]=='B'&&bs[2]=='C' || as[2]=='C'&&bs[2]=='B' || as[2]=='F'&&bs[2]=='D' || as[2]=='D'&&bs[2]=='F') cout<<1;
    else cout<<"0";
    return 0;
}
