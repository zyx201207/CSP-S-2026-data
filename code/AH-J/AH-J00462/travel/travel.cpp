#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
string rc,rs,xc,xs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc){
        cout<<'1';
        if(rs[0]==xs[0]&&rs[1]==xs[1]){
            cout<<'1';
            if((rs[2]>=65&&rs[2]<=67&&xs[2]>=65&&xs[2]<=67)||(rs[2]>=68&&rs[2]<=69&&xs[2]>=68&&xs[2]<=69)){
                cout<<'1';
                if(abs(rs[2]-xs[2])==1)cout<<'1';
                else cout<<'0';
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
