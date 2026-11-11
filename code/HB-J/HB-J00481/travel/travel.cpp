#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
string l1,l2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    l1=a2[0]+a2[1];
    l2=b2[0]+b2[1];
    if(a1==b1){
        cout<<1;
        if(l1==l2){
            cout<<1;
            if(a2[2]>=65&&a2[2]<=67&&b2[2]>=65&&b2[2]<=67){
                cout<<1;
                if(a2[2]+1==b2[2]||a2[2]-1==b2[2])cout<<1;
                else cout<<0;
            }
            else if(a2[2]>=68&&a2[2]<=70&&b2[2]>=68&&b2[2]<=70){
                cout<<1;
                if(a2[2]+2==b2[2]||a2[2]-2==b2[2])cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
